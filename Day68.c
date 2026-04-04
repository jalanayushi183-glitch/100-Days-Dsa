//  Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
 
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
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    struct Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int indegree[n];
    for (int i = 0; i < n; i++)
        indegree[i] = 0;

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        indegree[v]++;
    }

    int queue[n];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int count = 0;

    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);
        count++;

        struct Node* temp = adj[curr];
        while (temp) {
            indegree[temp->data]--;
            if (indegree[temp->data] == 0)
                queue[rear++] = temp->data;
            temp = temp->next;
        }
    }

    if (count != n)
        printf("\nCycle exists");

    return 0;
}