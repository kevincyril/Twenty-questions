#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

// Static function to create a new node
static struct node* create_node(int data, const char* question, const char* guess) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    // Check for NULL pointer after malloc
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1); // Exit if memory allocation fails
    }

    // Allocate memory and copy the question and guess strings
    newNode->data = data;
    newNode->question = (char*)malloc(strlen(question) + 1);
    if (newNode->question != NULL) {
        strcpy_s(newNode->question, strlen(question) + 1, question);
    }

    newNode->guess = (char*)malloc(strlen(guess) + 1);
    if (newNode->guess != NULL) {
        strcpy_s(newNode->guess, strlen(guess) + 1, guess);
    }

    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert function to add a new node to the tree
struct node* insert(struct node* root, int data, const char* question, const char* guess) {
    if (root == NULL) {
        return create_node(data, question, guess);
    }
    if (data < root->data) {
        root->left = insert(root->left, data, question, guess);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data, question, guess);
    }
    return root;
}

// Create the initial game tree
struct node* create_game_tree() {
    struct node* root = NULL;

    root = insert(root, 100, "Does it grow underground?", "");
    insert(root, 50, "Is it long in shape?", "");
    insert(root, 25, "Is it orange in color?", "");
    insert(root, 15, "", "It's a carrot!");
    insert(root, 35, "", "It's a parsnip!");
    insert(root, 75, "Is it red in color?", "");
    insert(root, 65, "", "It's a radish!");
    insert(root, 85, "", "It's a potato!");
    insert(root, 150, "Does it grow on a tree?", "");
    insert(root, 125, "Is it red in color?", "");
    insert(root, 115, "", "It's an apple!");
    insert(root, 135, "", "It's a peach!");
    insert(root, 175, "Is it red in color?", "");
    insert(root, 165, "", "It's a tomato!");
    insert(root, 185, "", "It's a pea!");

    return root;
}

// Free the memory allocated for the tree
void free_tree(struct node* root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root->question);
    free(root->guess);
    free(root);
}
