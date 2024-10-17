#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

void addEdge(int graph[MAX_VERTICES][MAX_VERTICES], int start, int end) {
    graph[start][end] = 1;
    graph[end][start] = 1;
}

//here we take vertex as an input to exploring it
void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int vertex, int visited[MAX_VERTICES], int failedNode, int vertices) {
    visited[vertex] = 1;

    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i] && i != failedNode) {
            DFS(graph, i, visited, failedNode, vertices);
        }
    }
}

// Function to check if the graph is connected
int isConnected(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int failedNode) {
    int visited[MAX_VERTICES] = {0};

    int startVertex = -1;
    for (int i = 0; i < vertices; i++) {
        if (i != failedNode) {
            startVertex = i;
            break;
        }
    }

    // If all nodes isolated
    if (startVertex == -1) return 0;

    //Perform DST for checking visiting the nodes
    DFS(graph, startVertex, visited, failedNode, vertices);

    // Check if all nodes, except the failed one, are visited
    for (int i = 0; i < vertices; i++) {
        if (i != failedNode && !visited[i]) {
            return 0;
        }
    }

    return 1;
}

void detectSingleNodeFailure(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    int criticalNodes[MAX_VERTICES] = {0};
    int criticalCount = 0;

    // Test each node as a failure
    for (int i = 0; i < vertices; i++) {
        if (!isConnected(graph, vertices, i)) {
            criticalNodes[criticalCount++] = i;
        }
    }

    if (criticalCount > 0) {
        printf("Critical nodes (single node failures that disconnect the network):\n");
        for (int i = 0; i < criticalCount; i++) {
            printf("Node %d\n", criticalNodes[i]);
        }
    } else {
        printf("No single node failures would disconnect the network.\n");
    }
}

int main() {
    int vertices, edges;


    printf("Input the number of vertices: ");
    scanf("%d", &vertices);

    if (vertices <= 0 || vertices > MAX_VERTICES) {
        printf("Invalid number of vertices. Exiting...\n");
        return 1;
    }

    int graph[MAX_VERTICES][MAX_VERTICES] = {0};


    printf("Input the number of edges: ");
    scanf("%d", &edges);

    if (edges < 0 || edges > vertices * (vertices - 1) / 2) {
        printf("Invalid number of edges. Exiting...\n");
        return 1;
    }

    for (int i = 0; i < edges; i++) {
        int start, end;
        printf("Input edge %d (start end): ", i + 1);
        scanf("%d %d", &start, &end);

        if (start < 0 || start >= vertices || end < 0 || end >= vertices) {
            printf("Invalid vertices. Try again.\n");
            i--;
            continue;
        }

        addEdge(graph, start, end);
    }

    // Detect single node failures
    detectSingleNodeFailure(graph, vertices);

    return 0;
}
