#include <stdio.h>
#include <stdlib.h>

// Definition of the structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insertion function
struct Node* insert(struct Node* root, int data) {
    // If the tree is empty, create a new node
    if (root == NULL) {
        return createNode(data);
    }

    // Otherwise, recursively insert data
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Helper function to find the minimum value node in the right subtree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    
    // Find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Deletion function
struct Node* deleteNode(struct Node* root, int data) {
    // Base case: if the tree is empty
    if (root == NULL) {
        return root;
    }

    // Recursively find the node to delete
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node to be deleted found

        // Case 1: Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Node with two children
        struct Node* temp = minValueNode(root->right);

        // Copy the inorder successor's value to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Search function
struct Node* search(struct Node* root, int data) {
    // Base cases: root is null or key is present at root
    if (root == NULL || root->data == data) {
        return root;
    }

    // Key is greater than root's key
    if (data > root->data) {
        return search(root->right, data);
    }

    // Key is smaller than root's key
    return search(root->left, data);
}

// Inorder traversal function to print the tree in sorted order
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to print the tree in a structured format
void printTree(struct Node* root, int space) {
    if (root == NULL) {
        return;
    }

    // Increase distance between levels
    space += 10;

    // Process right child first
    printTree(root->right, space);

    // Print current node after space count
    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    // Process left child
    printTree(root->left, space);
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Inorder Traversal\n5. Print Tree Structure\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct Node* searchResult = search(root, value);
                if (searchResult != NULL) {
                    printf("Value found in the tree.\n");
                } else {
                    printf("Value not found in the tree.\n");
                }
                break;
            case 4:
                printf("Inorder traversal of the tree: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Tree structure:\n");
                printTree(root, 0);
                printf("\n");
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
