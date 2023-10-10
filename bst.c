#include "bst.h"
#include <stdlib.h>
#include <string.h>

/*------------------------------------------------------------------
createNode
Here we create a node with the questions and the guesses took by the
compiler. The method first uses malloc to allocate a memory location,
creates nodes along with left and right. If its a leaf node, then the
left and right are assigned to NULL
 ------------------------------------------------------------------*/
struct node* createNode(int data, char* question, char* compilerGuess) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->question = strdup(question);
    newNode->compilerGuess = strdup(compilerGuess);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/*-----------------------------------------------------------------------
insertNode
This is a recursive function that adds new nodes to the binary tree with
specific questions and the guesses.
 -----------------------------------------------------------------------*/
struct node* insertNode(struct node* root, int data, char* question, char* compilerGuess) {
    if (root == NULL) {
        return createNode(data, question, compilerGuess);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data, question, compilerGuess);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data, question, compilerGuess);
    }
    return root;
}
