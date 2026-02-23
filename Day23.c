// Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print the merged linked list elements, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 35 45

// Output:
// 10 15 20 25 30 35 40 45 50

// Explanation:
// Compare nodes of both lists, append smaller to result, continue until all nodes are merged.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newnode;
    int value;

    for(int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);

        newnode->data = value;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

struct node* mergeLists(struct node* l1, struct node* l2) {
    struct node *result = NULL, *temp = NULL;

    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    if(l1->data <= l2->data) {
        result = l1;
        l1 = l1->next;
    } else {
        result = l2;
        l2 = l2->next;
    }

    temp = result;

    while(l1 != NULL && l2 != NULL) {
        if(l1->data <= l2->data) {
            temp->next = l1;
            l1 = l1->next;
        } else {
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }

    if(l1 != NULL)
        temp->next = l1;
    else
        temp->next = l2;

    return result;
}

void display(struct node* head) {
    printf("Merged Linked List: ");
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m;

    printf("Enter number of elements in first sorted list: ");
    scanf("%d", &n);
    printf("Enter elements of first sorted list:\n");
    struct node* list1 = createList(n);

    printf("Enter number of elements in second sorted list: ");
    scanf("%d", &m);
    printf("Enter elements of second sorted list:\n");
    struct node* list2 = createList(m);

    struct node* merged = mergeLists(list1, list2);

    display(merged);

    return 0;
}