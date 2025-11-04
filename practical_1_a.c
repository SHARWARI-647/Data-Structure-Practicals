/* 1 A.	Write a program to accept ‘n’ numbers into an array and then calculate the sum 
of numbers present in odd positions and even positions respectively.	*/
#include<stdio.h>
int main() {
    int n;
    int i ;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    int sum_odd = 0, sum_even = 0;

    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if(i % 2 == 0) // Odd position (0-based indexing)
            sum_odd += arr[i];
        else
            sum_even += arr[i];
    }

    printf("Sum of numbers at odd positions: %d\n", sum_odd);
    printf("Sum of numbers at even positions: %d\n", sum_even);

    return 0;
}
