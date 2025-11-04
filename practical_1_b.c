/*Write a program to implement a Binary Search algorithm. Write a search function which takes a SearchList as its first parameter and a Comparable as its second. If either parameter is null, or if the SearchList is empty, you should return NULL.
 implement the following algorithm: 
• Examine the value in the middle of the current array and print it. 
• If the midpoint value is the value that we are looking for, return true 
• If the value that we are looking for is greater than the midpoint value, adjust the current array to start at the midpoint and print the index.
• if the value that we are looking for is less than the midpoint value, adjust the current array to end at the midpoint  and print the index.
• Continue until you find the value, or until the start reaches the end, 
*/
#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    if(arr == NULL || n <= 0)
        return -1;

    int start = 0, end = n - 1;
    while(start <= end) {
        int mid = (start + end) / 2;
        printf("Middle value: %d\n", arr[mid]);

        if(arr[mid] == key)
            return mid; // Found
        else if(arr[mid] < key) {
            start = mid + 1;
            printf("Adjust start to index: %d\n", start);
        } else {
            end = mid - 1;
            printf("Adjust end to index: %d\n", end);
        }
    }
    return -1; // Not found
}

int main() {
    int n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter sorted elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the value to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, n, key);
    if(result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
