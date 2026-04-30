// Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
// Distribute into buckets, sort each, concatenate.
#include <stdio.h>

void insertionSort(float arr[], int n) {
    for(int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    float bucket[n][n];
    int count[n];

    for(int i = 0; i < n; i++) count[i] = 0;

    for(int i = 0; i < n; i++) {
        int index = n * arr[i];
        bucket[index][count[index]++] = arr[i];
    }

    for(int i = 0; i < n; i++) {
        insertionSort(bucket[i], count[i]);
    }

    int k = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < count[i]; j++) {
            arr[k++] = bucket[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}