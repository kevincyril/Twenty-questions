#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

// Function to play the game
void play_game(struct node* root) {
    struct node* current = root;
    char answer[3]; // For 'y' or 'n'

    while (current != NULL) {
        if (strcmp(current->question, "") != 0) {
            // Ask a question
            printf("%s\n", current->question);
            printf("y/n: ");
            scanf_s("%2s", answer, (unsigned)_countof(answer));

            // Ensure null termination of the input
            answer[2] = '\0';

            if (strcmp(answer, "y") == 0) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        else {
            // Make a guess
            printf("%s\n", current->guess);
            printf("y/n: ");
            scanf_s("%2s", answer, (unsigned)_countof(answer));

            // Ensure null termination of the input
            answer[2] = '\0';

            if (strcmp(answer, "y") == 0) {
                printf("I win!\n");
            }
            else {
                printf("You win!\n");
            }
            return;
        }
    }
}

int main() {
    struct node* game_tree = create_game_tree();
    char c;

    printf("Welcome! Press 'q' to quit or any other key to continue:\n");
    while (1) {
        scanf_s(" %c", &c, 1);
        if (c == 'q') break;

        printf("You think of a fruit or vegetable and I will try to guess it!\n");
        play_game(game_tree);
        printf("Press 'q' to quit or any other key to continue:\n");
    }

    free_tree(game_tree);
    printf("Bye Bye!\n");
    return 0;
}
