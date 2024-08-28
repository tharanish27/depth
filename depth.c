#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a tree node
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find the depth of a specific node
int findDepth(TreeNode* root, int target, int currentDepth) {
    // Base case: If the tree is empty
    if (root == NULL) {
        return -1; // Return -1 if the node is not found
    }

    // If the current node is the target node, return the current depth
    if (root->value == target) {
        return currentDepth;
    }

    // Recursively search in the left and right subtrees
    int leftDepth = findDepth(root->left, target, currentDepth + 1);
    if (leftDepth != -1) {
        return leftDepth; // If the node is found in the left subtree
    }

    return findDepth(root->right, target, currentDepth + 1); // Search in the right subtree
}

// Main function to demonstrate finding the depth of a specific node
int main() {
    // Create a simple binary tree
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Define the target value to search for
    int target = 5;

    // Find and print the depth of the target node
    int depth = findDepth(root, target, 0);
    if (depth != -1) {
        printf("Depth of node %d: %d\n", target, depth);
    } else {
        printf("Node %d not found in the tree.\n", target);
    }
    
    // Free allocated memory (not shown here for simplicity)
    // Implement proper cleanup in real code

    return 0;
}
