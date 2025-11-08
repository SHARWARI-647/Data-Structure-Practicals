/*3	Design, Develop and Implement a menu driven Program in C for the following operations on QUEUE of Characters (Array Implementation of Queue with maximum size MAX)
a. Insert an Element on to QUEUE
b. Delete an Element from QUEUE
c. Demonstrate Overflow and Underflow situations on QUEUE
d. Display the status of QUEUE
e. Exit
Support the program with appropriate functions for each of the above operations.	
*/
/* Linear Queue */ 
#include<stdio.h> 
#include<conio.h> 
#define MAX 5 
struct queue 
{ 
int a[MAX]; 
int f,r; 
}; 
void init(struct queue *q) 
{ 
q->f=q->r=-1; 
} 
int isempty(struct queue *q) 
{ 
if(q->r==-1) 
return 1; 
else 
return 0; 
} 
int isfull(struct queue *q) 
{ 
if(q->r==MAX-1) 
return 1; 
else 
return 0; 
} 
void insert(struct queue *q,int x) 
{ 
if(q->r==-1) 
{ 
q->f=q->r=0; 
} 
else 
{ 
q->r=q->r+1; 
} 
q->a[q->r]=x; 
} 
int delete(struct queue *q) 
{ 
int x; 
x=q->a[q->f]; 
if(q->f==q->r) 
{ 
q->f=q->r=-1; 
} 
else 
{ 
q->f=q->f+1; 
} 
return x; 
} 
void print(struct queue *q) 
{ 
int i; 
printf("\n"); 
for(i=q->f;i<=q->r;i++) 
printf("%d\t",q->a[i]); 
} 
void main() 
{ 
struct queue q; 
int x,op;   
init(&q); 
printf("1.Insert\n2.Delete\n3.Print\n4.Quit"); 
do 
 { 
  printf("\nEnter choice: "); 
  scanf("%d",&op); 
   
switch(op) 
  { 
   case 1: 
    if(isfull(&q)) 
     printf("\nOverflow"); 
    else 
    { 
     printf("\nEnter value: "); 
     scanf("%d",&x); 
     insert(&q,x); 
    } 
     break; 
   case 2: 
    if(isempty(&q)) 
     printf("\nUnderflow"); 
    else 
    { 
     x=delete(&q); 
     printf("\nDeleted Value=%d",x); 
    } 
    break; 
   case 3: 
    print(&q); 
    break; 
  } 
 }while(op!=4); 
} 