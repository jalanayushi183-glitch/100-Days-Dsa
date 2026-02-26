// Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print value of intersection node or 'No Intersection'

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 30 40 50

// Output:
// 30

// Explanation:
// Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    struct Node* longer = (len1 > len2) ? head1 : head2;
    struct Node* shorter = (len1 > len2) ? head2 : head1;

    for (int i = 0; i < diff; i++)
        longer = longer->next;

    while (longer != NULL && shorter != NULL) {
        if (longer == shorter)
            return longer;

        longer = longer->next;
        shorter = shorter->next;
    }

    return NULL;
}

int main() {
    int n, m, val;

    struct Node *head1 = NULL, *tail1 = NULL;
    struct Node *head2 = NULL, *tail2 = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);

        if (head1 == NULL)
            head1 = tail1 = newNode;
        else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);

        if (head2 == NULL)
            head2 = tail2 = newNode;
        else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    struct Node* temp1 = head1;
    struct Node* temp2 = head2;

    while (temp2 != NULL) {
        temp1 = head1;
        while (temp1 != NULL) {
            if (temp1->data == temp2->data) {
                tail2->next = temp1;   
                temp2 = NULL;
                break;
            }
            temp1 = temp1->next;
        }
        if (temp2 != NULL)
            temp2 = temp2->next;
    }

    struct Node* result = findIntersection(head1, head2);

    if (result != NULL)
        printf("%d\n", result->data);
    else
        printf("No Intersection\n");

    return 0;
}