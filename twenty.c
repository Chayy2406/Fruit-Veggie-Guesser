#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

/*--------------------------------------------------------------------
createTree
Here we define a method to create the tree structure loosely based off
the given example tree code given in the A7 pdf file. Here, we have the
binary tree with a bunch of questions and answers to the questions. The
user traverses the tree through these questions.
--------------------------------------------------------------------*/
struct node* createTree() {
    struct node* root = NULL;
    root = insertNode(root, 100, "Does it grow underground?", "");
    insertNode(root, 50, "Is it long in shape?", "");
    insertNode(root, 25, "Is it orange in color?", "");
    insertNode(root, 15, "", "It's a carrot!");
    insertNode(root, 35, "", "It's a parsnip!");
    insertNode(root, 75, "Is it red in color?", "");
    insertNode(root, 65, "", "It's a radish!");
    insertNode(root, 85, "", "It's a potato!");
    insertNode(root, 150, "Does it grow on a tree?", "");
    insertNode(root, 125, "Is it red in color?", "");
    insertNode(root, 115, "", "It's an apple!");
    insertNode(root, 135, "", "It's a peach!");
    insertNode(root, 175, "Is it red in color?", "");
    insertNode(root, 165, "", "It's a tomato!");
    insertNode(root, 185, "", "It's a pea!");
    return root;
}

/*--------------------------------------------------------------------
play
This is the recursive function that makes the game possible to play.
This method takes the node as the input. This node gets updated for
each recursive call. This is how it recurses. So the compiler first
checks question. Based on the given user response, the compiler
moves around the tree.
--------------------------------------------------------------------*/
void play(struct node* node) {
    //if the compiler goes to a node with the questions, the compiler goes around based on the input
    if (*node->question) {
        printf("%s\ny/n: ", node->question);
        char answer;
        scanf(" %c", &answer);
        if (answer == 'y') {
        	//if the user says yes to a question, the compiler goes left in the tree.
            play(node->left);
        } else if (answer == 'n') {
        	//if the user says no to a question, the compiler goes right in the tree.
            play(node->right);
        }
    } else {
        //if the compiler comes to the leaf node, then we check the guess.
        printf("%s\ny/n: ", node->compilerGuess);
        char answer;
        scanf(" %c", &answer);
        if (answer == 'y') {
        	//if the code made the correct guess, then it says "I win!"
            printf("I win!\n");
        } else {
        	//if you thought of a different fruit/vegetable, then it says "You win!"
            printf("You win!\n");
        }
    }
}

/*--------------------------------------------------------------------
main
This is the main face of the program. This is where the program starts,
with a welcome message and this is where we call the methods.
We use a loop to make sure that the player gets to play the game again.
--------------------------------------------------------------------*/
int main() {
	char c;
    struct node* binaryTree = createTree();
    printf("Welcome! Press 'q' to quit or any other key to continue:\n");
    while (1) {
        scanf(" %c", &c);
        if (c == 'q') break;
        printf("You think of a fruit or vegetable and I will try to guess it!\n");
        //Here we call the recursive function with the tree
        play(binaryTree);
        printf("Press 'q' to quit or any other key to continue:\n");
    }
    printf("Bye Bye!\n");
    return 0;
}
