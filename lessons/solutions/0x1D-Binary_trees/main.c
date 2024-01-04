#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Function prototype
node *create();

int main(void) {
    node *root = NULL; // Initialize to NULL
    
    // Call the create function to build the tree
    root = create();

    if (root != NULL) {
        printf("Root data: %d\n", root->data);
    } else {
        printf("Tree is empty.\n");
    }

    return 0;
}

// Function to create a binary tree
node *create() {
    int x;

    // Allocate memory for a new node
    node *newnode = malloc(sizeof(node));

    if (newnode == NULL) {
        // Memory allocation failed
        printf("Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Prompt user for data input
    printf("Enter the data for the node (-1 to terminate): ");
    scanf("%d", &x);

    if (x == -1) {
        free(newnode); // Free the allocated memory for the current node
        return NULL;   // Return NULL to indicate the end of the tree
    }

    // Set the data for the current node
    newnode->data = x;

    // Recursively create the left and right subtrees
    printf("Enter data for the left child of %d:\n", x);
    newnode->left = create();

    printf("Enter data for the right child of %d:\n", x);
    newnode->right = create();

    return newnode; // Return the created node
}
