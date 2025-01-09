#ifndef BST_H
#define BST_H

struct node {
    int data;
    char* question;
    char* guess;
    struct node* left;
    struct node* right;
};

// Function declarations
struct node* insert(struct node* root, int data, char* question, char* guess);
struct node* create_game_tree();
void play_game(struct node* root);
void free_tree(struct node* root);

#endif

