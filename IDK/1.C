#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value)
{
    if (rear == MAX - 1)
        printf("Overflow\n");
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
        printf("Underflow\n");
    else
        front++;
}

void display()
{
    if (front == -1 || front > rear)
        printf("Queue is empty\n");
    else
    {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}