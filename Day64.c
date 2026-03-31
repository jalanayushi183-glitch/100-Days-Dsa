// Problem: Perform BFS from a given source using queue.

// Input:
// - n
// - adjacency list
// - source s

// Output:
// - BFS traversal order
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int m;
    scanf("%d", &m);

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    int s;
    scanf("%d", &s);

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int queue[n];
    int front = 0, rear = 0;

    visited[s] = 1;
    queue[rear++] = s;

    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        struct Node* temp = adj[curr];
        while (temp) {
            if (!visited[temp->data]) {
                visited[temp->data] = 1;
                queue[rear++] = temp->data;
            }
            temp = temp->next;
        }
    }

    return 0;
}