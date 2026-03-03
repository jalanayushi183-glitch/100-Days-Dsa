// Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

// Input:
// - First line: integer n (number of operations)
// - Next n lines: operation type and value (if applicable)
//   - 1 value: push value
//   - 2: pop
//   - 3: display

// Output:
// - For display: print stack elements from top to bottom
// - For pop: print popped element or 'Stack Underflow'

// Example:
// Input:
// 5
// 1 10
// 1 20
// 3
// 2
// 3

// Output:
// 20 10
// 20
// 10
#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed into stack\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        printf("Stack elements (Top to Bottom): ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int n, operation, value;

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("\nEnter operation (1-Push, 2-Pop, 3-Display): ");
        scanf("%d", &operation);

        if (operation == 1) {
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
        } 
        else if (operation == 2) {
            pop();
        } 
        else if (operation == 3) {
            display();
        } 
        else {
            printf("Invalid operation\n");
        }
    }

    return 0;
}