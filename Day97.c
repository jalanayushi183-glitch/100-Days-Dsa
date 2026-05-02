// Problem: Given meeting intervals, find minimum number of rooms required.
// Sort by start time and use min-heap on end times.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int cmpStart(const void *a, const void *b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int heap[], int n, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && heap[l] < heap[smallest]) smallest = l;
    if(r < n && heap[r] < heap[smallest]) smallest = r;

    if(smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

void insertHeap(int heap[], int *size, int val) {
    int i = (*size)++;
    heap[i] = val;

    while(i != 0 && heap[(i-1)/2] > heap[i]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

int extractMin(int heap[], int *size) {
    int root = heap[0];
    heap[0] = heap[--(*size)];
    heapify(heap, *size, 0);
    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(Interval), cmpStart);

    int heap[n], size = 0;
    insertHeap(heap, &size, arr[0].end);

    int maxRooms = 1;

    for(int i = 1; i < n; i++) {
        if(arr[i].start >= heap[0]) {
            extractMin(heap, &size);
        }
        insertHeap(heap, &size, arr[i].end);
        if(size > maxRooms) maxRooms = size;
    }

    printf("%d", maxRooms);

    return 0;
}