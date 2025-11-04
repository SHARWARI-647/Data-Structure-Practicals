/*Write a program to insert Number of Nodes in the Binary Tree and Traverse in Inorder , 
Preorder and Post Order and  Search an element in Binary Tree(Display NULL if not found, If found Display Found).*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct Node* insert (struct Node* root,int x){
    if(root==NULL){
        root=createNode(x);
    } else if(root->data<x){
        root->left=insert(root->left,x);
    }else if(root->data>x){
        root->right=insert(root->right,x);
    }
return root;
}

void preorder(struct Node* t){
      if(t!=NULL){
        printf("%d ",t->data);
         preorder(t->left);
         preorder(t->right);
      }
}

void inorder(struct Node* t){
      if(t!=NULL){
        inorder(t->left);
        printf("%d ",t->data);
        inorder(t->right);
      }
}

void postorder(struct Node* t){
      if(t!=NULL){
        postorder(t->left);
        postorder(t->right);
        printf("%d ",t->data);
      }
}

void search(struct Node* root,int key){
      if(root!=NULL){
        if(root==key){
            printf("key found..");
        }else{
            if(root->data>key)
                search(root->right,key);
            else
                search(root->right,key);
        }
      }else{
          printf("key not found");
      }
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n5. Search\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
               printf("Enter key to search: ");
               scanf("%d", &value);
               search(root, value);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}   