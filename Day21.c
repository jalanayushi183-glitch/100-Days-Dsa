// Problem: Create and Traverse Singly Linked List

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the result

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50
#include <stdio.h>
#include <stdlib.h>

// Define structure
struct node {
    int data;
    struct node *next;
};

int main() {
    int n, i;

    printf("Enter the number of nodes (n): ");
    scanf("%d", &n);

    struct node *head = NULL, *temp = NULL, *newnode = NULL;

    printf("Enter %d space-separated integers: ", n);

    for(i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = head;
        }
        else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    printf("Linked List elements: ");
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}