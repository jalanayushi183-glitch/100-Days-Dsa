#include <stdio.h>

int q[100];
int front = 0, rear = -1;

void enqueue(int x)
{
    rear++;
    q[rear] = x;
}

int dequeue()
{
    int x = q[front];
    front++;
    return x;
}

void push(int x)
{
    int size = rear - front + 1;
    enqueue(x);
    for (int i = 0; i < size; i++)
        enqueue(dequeue());
}

void pop()
{
    if (front > rear)
        printf("Empty\n");
    else
        front++;
}

void display()
{
    for (int i = front; i <= rear; i++)
        printf("%d ", q[i]);
    printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    return 0;
}