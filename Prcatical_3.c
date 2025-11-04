/*3	Design, Develop and Implement a menu driven Program in C for the following operations on QUEUE of Characters (Array Implementation of Queue with maximum size MAX)
a. Insert an Element on to QUEUE
b. Delete an Element from QUEUE
c. Demonstrate Overflow and Underflow situations on QUEUE
d. Display the status of QUEUE
e. Exit
Support the program with appropriate functions for each of the above operations.	
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5   // Maximum size of the queue

char queue[MAX];
int front = -1, rear = -1;

// Function to insert an element into the queue
void insert() {
    char element;

    if (rear == MAX - 1) {
        printf("\nQueue Overflow! Cannot insert more elements.\n");
        return;
    }

    printf("Enter a character to insert: ");
    scanf(" %c", &element);

    if (front == -1) front = 0; // First insertion
    rear++;
    queue[rear] = element;

    printf("'%c' inserted into the queue.\n", element);
}

// Function to delete an element from the queue
void delete() {
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow! No elements to delete.\n");
        front = rear = -1; // Reset queue
        return;
    }

    printf("Deleted element: '%c'\n", queue[front]);
    front++;

    // Reset queue when last element is deleted
    if (front > rear) {
        front = rear = -1;
    }
}

// Function to display the queue
void display() {
    if (front == -1) {
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\nCurrent Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%c ", queue[i]);
    }
    printf("\nFront = %d, Rear = %d\n", front, rear);
}

// Main function with menu-driven implementation
int main() {
    int choice;

    while (1) {
        printf("\n===== QUEUE OPERATIONS MENU =====");
        printf("\n1. Insert an Element");
        printf("\n2. Delete an Element");
        printf("\n3. Display Queue");
        printf("\n4. Exit");
        printf("\n----------------------------------");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}
