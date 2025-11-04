/*Write a program which creates a structure Student which must have the attribute 
Avg Marks with 3 more attributes sort the list of the student in descending order using Bubble sort.
*/
#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int roll;
    float AvgMarks;
};

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    
    struct Student s[n];
    for(int i = 0; i < n; i++) {
        printf("Enter name, roll, avg marks for student %d: ", i+1);
        scanf("%s %d %f", s[i].name, &s[i].roll, &s[i].AvgMarks);
    }

    // Bubble Sort Descending
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(s[j].AvgMarks < s[j+1].AvgMarks) {
                struct Student temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }

    printf("Students sorted by Avg Marks (Descending):\n");
    for(int i = 0; i < n; i++)
        printf("%s %d %.2f\n", s[i].name, s[i].roll, s[i].AvgMarks);

    return 0;
}
