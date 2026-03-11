// Problem Statement:
// Implement a Min Heap using an array where the smallest element is always at the root.

// Supported Operations:
// - insert x
// - extractMin
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain heap operations

// Output Format:
// - Print results of extractMin and peek
// - Print -1 if operation cannot be performed

// Example:
// Input:
// 6
// insert 40
// insert 10
// insert 30
// peek
// extractMin
// peek

// Output:
// 10
// 10
// 30
#include <stdio.h>
#include <string.h>

#define MAX 100

int heap[MAX];
int size = 0;

int result[MAX];
int rIndex = 0;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void insert(int x)
{
    heap[size] = x;
    int i = size;
    size++;

    while(i != 0 && heap[(i-1)/2] > heap[i])
    {
        swap(&heap[(i-1)/2], &heap[i]);
        i = (i-1)/2;
    }
}

void heapify(int i)
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && heap[left] < heap[smallest])
        smallest = left;

    if(right < size && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i)
    {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

void extractMin()
{
    if(size <= 0)
    {
        result[rIndex++] = -1;
        return;
    }

    result[rIndex++] = heap[0];

    heap[0] = heap[size-1];
    size--;

    heapify(0);
}

void peek()
{
    if(size <= 0)
        result[rIndex++] = -1;
    else
        result[rIndex++] = heap[0];
}

int main()
{
    int N, x;
    char op[20];

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%s", op);

        if(strcmp(op,"insert")==0)
        {
            scanf("%d",&x);
            insert(x);
        }
        else if(strcmp(op,"extractMin")==0)
            extractMin();

        else if(strcmp(op,"peek")==0)
            peek();
    }

    for(int i = 0; i < rIndex; i++)
        printf("%d\n", result[i]);

    return 0;
}