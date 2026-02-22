// Problem: Given an array of integers, rotate the array to the right by k positions.

// Input:
// - First line: integer n
// - Second line: n integers
// - Third line: integer k

// Output:
// - Print the rotated array

// Example:
// Input:
// 5
// 1 2 3 4 5
// 2

// Output:
// 4 5 1 2 3
#include <stdio.h>

int main() {
    int n, k, i;

    printf("Enter the number of elements (n): ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integers: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number of positions to rotate (k): ");
    scanf("%d", &k);

    k = k % n;

    int left = 0, right = n - 1, temp;
    while(left < right) {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }

    left = 0;
    right = k - 1;
    while(left < right) {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }

    left = k;
    right = n - 1;
    while(left < right) {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }

    printf("Array after right rotation: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}