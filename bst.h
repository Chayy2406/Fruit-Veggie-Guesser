#ifndef BST_H
#define BST_H

//Here we are defining the structure for our binary tree
struct node {
    int data;                   //we use this int type variable to track the traverse
    char* question;             //This is the question askerd by the compiler
    char* compilerGuess;        //This is the guess that the code has
    struct node* left;          //this points to the left node
    struct node* right;         //this points to the right node
};

struct node* createNode(int data, char* question, char* compilerGuess);
struct node* insertNode(struct node* root, int data, char* question, char* compilerGuess);

#endif
