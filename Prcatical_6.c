/*Implement Binary search tree(BST) with following Menu operations.
1.	Search an element in BST(Display NULL if not found, If found Display Found)
2.	Insert an element in BST
3.	Delete leaf element in BST
4.	Exit
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert node recursively
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Search for a key in BST
void search(struct Node* root, int key) {
    if (root == NULL) {
        printf("NULL\n");
        return;
    }

    if (key == root->data) {
        printf("Found\n");
    } else if (key < root->data) {
        search(root->left, key);
    } else {
        search(root->right, key);
    }
}

// Delete only leaf nodes
struct Node* deleteLeaf(struct Node* root, int value) {
    if (root == NULL)
        return NULL;

    if (value < root->data)
        root->left = deleteLeaf(root->left, value);
    else if (value > root->data)
        root->right = deleteLeaf(root->right, value);
    else {
        // Found the node — delete only if it is a leaf
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else {
            printf("Cannot delete! Node is not a leaf.\n");
        }
    }
    return root;
}

// Menu-driven main function
int main() {
    struct Node* root = NULL;
    int choice, value, n, i;

    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Search an element in BST\n");
        printf("2. Insert an element in BST\n");
        printf("3. Delete leaf element in BST\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(root, value);
                break;

            case 2:
                printf("Enter number of elements: ");
                scanf("%d", &n);
                printf("Enter elements: ");
                for (i = 0; i < n; i++) {
                    scanf("%d", &value);
                    root = insert(root, value);
                }
                printf("All Elements inserted successfully.");
                printf("\n");
                break;

            case 3:
                printf("Enter leaf node value to delete: ");
                scanf("%d", &value);
                root = deleteLeaf(root, value);
                printf("Leaf node %d deletion : ",value);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
