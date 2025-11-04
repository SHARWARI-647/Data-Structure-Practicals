/*Design, Develop and Implement a menu driven Program in C for the following operations on STACK of Integers (Array Implementation of Stack with maximum size MAX) 
a. Push an Element on to Stack 
b. Pop an Element from Stack 
c. Demonstrate how Stack can be used to check Palindrome 
d. Demonstrate Overflow and Underflow situations on Stack 
e. Display the status of Stack 
f. Exit 
Support the program with appropriate functions for each of the above operations.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Stack {
    int arr[MAX];
    int top;
};

void init(struct Stack *s) {
    s->top = -1;
}

int isfull(struct Stack *s) {
    if (s->top == MAX - 1)
        return 1;
    else
        return 0;
}

int isempty(struct Stack *s) {
    if (s->top == -1)
        return 1;
    else
        return 0;
}

void push(struct Stack *s, int x) {
    s->top++;
    s->arr[s->top] = x;
}

int pop(struct Stack *s) {
    int x = s->arr[s->top];
    s->top--;
    return x;
}

void print(struct Stack *s) {
    int i;
    for (i = s->top; i >= 0; i--)
        printf("%d ", s->arr[i]);
    printf("\n");
}

void checkPalindrome(struct Stack *s,char str[50]) {
    char rev[50];
    int len = strlen(str);

    char stk[len];
    int t = -1;

    for(int i = 0; i < len; i++)
        stk[++t] = str[i]; // push characters

    for(int i = 0; i < len; i++)
        rev[i] = stk[t--]; // pop characters

    rev[len] = '\0';
    if(strcmp(str, rev) == 0)
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");
}
int main() {
    struct Stack s;
    init(&s);
    int ch, n;
      printf("E \n 1. Push \n 2. Pop \n 3. Print \n 4. Exit\n");
    while (1) {
        printf("nter a choice : ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            if (isfull(&s))
                printf("The Stack is Overflow\n");
            else {
                printf("Enter the number: ");
                scanf("%d", &n);
                push(&s, n);
            }
            break;
        case 2:
            if (isempty(&s))
                printf("The Stack is Underflow\n");
            else {
                printf("The deleted element is: %d\n", pop(&s));
            }
            break;
        case 3:
            print(&s);
            break;

        case 4:
        char str[50];
        printf("Enter string to check palindrome: ");
        scanf("%s", str);
    checkPalindrome(&s,str);break;
        case 5:
            exit(0);break;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
