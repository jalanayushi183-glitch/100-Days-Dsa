// Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements to enqueue)
// - Second line: n space-separated integers
// - Third line: integer m (number of dequeue operations)

// Output:
// - Print queue elements from front to rear after operations, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 30 40 50 10 20

// Explanation:
// Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.
#include <stdio.h>

#define MAX 100

int main()
{
    int queue[MAX];
    int front = 0, rear = -1;
    int n, m, i;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &queue[i]);
        rear++;
    }

    scanf("%d", &m);

    for(i = 0; i < m; i++)
    {
        int temp = queue[front];     
        front = (front + 1) % MAX;

        rear = (rear + 1) % MAX;     
        queue[rear] = temp;
    }

    i = front;
    while(1)
    {
        printf("%d ", queue[i]);
        if(i == rear)
            break;
        i = (i + 1) % MAX;
    }

    return 0;
}