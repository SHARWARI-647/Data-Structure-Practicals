//This C program implements a menu-driven binary search tree (BST) with recursive functions for 
//insertion, deletion, traversal (inorder, preorder, postorder), searching, and finding minimum and maximum values.
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

// Recursive insert
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Recursive inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Recursive preorder traversal
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Recursive postorder traversal
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Recursive search
void search(struct Node* root, int key) {
    if (root == NULL) {
        printf("Key not found!\n");
        return;
    }

    if (key == root->data) {
        printf("Key found!\n");
    } else if (key < root->data) {
        search(root->left, key);
    } else {
        search(root->right, key);
    }
}

// Recursive min value node finder
struct Node* findMin(struct Node* root) {
    if (root == NULL || root->left == NULL)
        return root;
    return findMin(root->left);
}

// Recursive max value node finder
struct Node* findMax(struct Node* root) {
    if (root == NULL || root->right == NULL)
        return root;
    return findMax(root->right);
}

// Recursive delete
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        // Node found
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        } else {
            // Two children: find inorder successor
            struct Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// Menu-driven main function
int main() {
    struct Node* root = NULL;
    int choice, value,n;

    while (1) {
        printf("\n--- Recursive Binary Search Tree Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Inorder Traversal\n4. Preorder Traversal\n5. Postorder Traversal\n");
        printf("6. Search\n7. Find Minimum\n8. Find Maximum\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter no. elemnts:: ");
                scanf("%d",&n);
                printf("Enter value to insert: ");
                int arr[n];
                for(int i=0;i<n;i++){
                   scanf("%d", &arr[i]);
                   value=arr[i];
                   root = insert(root, value);
                }
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 3:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 5:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 6:
                printf("Enter key to search: ");
                scanf("%d", &value);
                search(root, value);
                break;

            case 7: {
                struct Node* minNode = findMin(root);
                if (minNode)
                    printf("Minimum value: %d\n", minNode->data);
                else
                    printf("Tree is empty!\n");
                break;
            }

            case 8: {
                struct Node* maxNode = findMax(root);
                if (maxNode)
                    printf("Maximum value: %d\n", maxNode->data);
                else
                    printf("Tree is empty!\n");
                break;
            }

            case 9:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}







                 36
                 /\
               26  46
              / \  / \
             21 31 41 56
            / \        \
           11  24      66