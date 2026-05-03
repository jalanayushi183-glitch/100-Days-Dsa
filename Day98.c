// Problem: Given intervals, merge all overlapping ones.
// Sort first, then compare with previous.
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int cmp(const void *a, const void *b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(Interval), cmp);

    int i = 0;

    while(i < n) {
        int start = arr[i].start;
        int end = arr[i].end;

        int j = i + 1;

        while(j < n && arr[j].start <= end) {
            if(arr[j].end > end) {
                end = arr[j].end;
            }
            j++;
        }

        printf("%d %d\n", start, end);
        i = j;
    }

    return 0;
}