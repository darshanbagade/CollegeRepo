#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Function to add an edge to the graph
void addEdge(int graph[MAX_VERTICES][MAX_VERTICES], int start, int end) {
    graph[start][end] = 1;
    graph[end][start] = 1; // For undirected graph
}

// Recursive function to perform DFS and check for cycles
int isCyclicUtil(int graph[MAX_VERTICES][MAX_VERTICES], int currentVertex, int parent, int visited[MAX_VERTICES], int vertices) {
    visited[currentVertex] = 1;

    // Only iterate up to the number of vertices
    for (int i = 0; i < vertices; i++) {
        if (graph[currentVertex][i]) {
            if (!visited[i]) {
                if (isCyclicUtil(graph, i, currentVertex, visited, vertices))
                    return 1;
            } else if (i != parent) {
                return 1; // Found a back edge, so there's a cycle
            }
        }
    }

    return 0;
}

// Function to check whether a graph contains a cycle
int isCyclic(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    int visited[MAX_VERTICES] = {0}; // Initialize visited array

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(graph, i, -1, visited, vertices))
                return 1; // Cycle found
        }
    }

    return 0; // No cycle found
}

int main() {
    int vertices, edges;

    // Input the number of vertices
    printf("Input the number of vertices: ");
    scanf("%d", &vertices);

    if (vertices <= 0 || vertices > MAX_VERTICES) {
        printf("Invalid number of vertices. Exiting...\n");
        return 1;
    }

    int graph[MAX_VERTICES][MAX_VERTICES] = {0}; // Initialize the adjacency matrix with zeros

    // Input the number of edges
    printf("Input the number of edges: ");
    scanf("%d", &edges);

    if (edges < 0 || edges > vertices * (vertices - 1) / 2) {
        printf("Invalid number of edges. Exiting...\n");
        return 1;
    }

    // Input edges and construct the adjacency matrix
    for (int i = 0; i < edges; i++) {
        int start, end;
        printf("Input edge %d (start end): ", i + 1);
        scanf("%d %d", &start, &end);

        // Validate input vertices
        if (start < 0 || start >= vertices || end < 0 || end >= vertices) {
            printf("Invalid vertices. Try again.\n");
            i--;
            continue;
        }

        addEdge(graph, start, end);
    }

    // Check if the graph contains a cycle
    if (isCyclic(graph, vertices))
        printf("The graph contains a cycle.\n");
    else
        printf("The graph does not contain a cycle.\n");

    return 0;
}
