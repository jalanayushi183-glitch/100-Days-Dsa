// Problem: For each element, count how many smaller elements appear on right side.
// Use merge sort technique or Fenwick Tree (BIT)
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val, idx;
} Node;

void merge(Node arr[], int left, int mid, int right, int count[]) {
    int n = right - left + 1;
    Node temp[n];
    int i = left, j = mid + 1, k = 0;
    int rightCount = 0;

    while(i <= mid && j <= right) {
        if(arr[i].val <= arr[j].val) {
            count[arr[i].idx] += rightCount;
            temp[k++] = arr[i++];
        } else {
            rightCount++;
            temp[k++] = arr[j++];
        }
    }

    while(i <= mid) {
        count[arr[i].idx] += rightCount;
        temp[k++] = arr[i++];
    }

    while(j <= right) {
        temp[k++] = arr[j++];
    }

    for(int x = 0; x < n; x++) {
        arr[left + x] = temp[x];
    }
}

void mergeSort(Node arr[], int left, int right, int count[]) {
    if(left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid, count);
        mergeSort(arr, mid + 1, right, count);
        merge(arr, left, mid, right, count);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n], count[n];
    Node arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        arr[i].val = a[i];
        arr[i].idx = i;
        count[i] = 0;
    }

    mergeSort(arr, 0, n - 1, count);

    for(int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}