// Problem: Implement Binary Search Iterative - Implement the algorithm.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the sorted array or search result

// Example:
// Input:
// 5
// 64 34 25 12 22

// Output:
// 12 22 25 34 64
#include <stdio.h>

int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(arr[mid] == x) return mid;
        else if(arr[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}