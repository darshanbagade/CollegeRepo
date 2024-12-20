#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_VERTICES 100


int graph[MAX_VERTICES][MAX_VERTICES] = {0} ;
int visited[MAX_VERTICES]={0};
int vertices;
int edges;

void addEdge(int start, int end){
    graph[start][end] = 1;
    graph[end][start] = 1;
}

int DFS( int vertex, int failedNode){
    int count = 1;
    visited[vertex] = 1;
    for(int i=0 ; i < vertices ; i++){
        if( (graph[vertex][i]== 1) && (i != failedNode) && (!visited[i]) )
        {
            count += DFS(i, failedNode);

        }
    }
    return count;

}

int isConnected(int failedNode){
    for(int i=0 ; i <vertices ; i++){
        visited[i] = 0;
    }

    int visitedCount;
    int startVertex = -1;

    for(int i=0 ; i< vertices ; i++){
        if(i != failedNode){
            startVertex = i;
            break;
        }
    }

    if(startVertex == -1){
        return 0 ;
    }

    visitedCount = DFS(startVertex, failedNode);

    return ( visitedCount == vertices-1 );


}

void detectSingleFailureNode(){
    int criticalNode[MAX_VERTICES] = {0};
    int criticalCount = 0;

    //checking for every node is faileNode or not
    for(int i = 0 ; i < vertices ; i++ ){
        if(!isConnected(i)){
            criticalNode[criticalCount++] = i;
        }
    }


    //checking for critical nodes in graph
    if(criticalCount>0){
        printf("Single Failure Node in the graph: \n");
        for(int i = 0 ; i<criticalCount ; i++ ){
            printf("Node : %d ", criticalNode[i]);
        }
    }
    else{
        printf("No single failure Node is found in the graph\n");
    }


}

int main(){
    int start,end;


    printf("Enter the number of vertices : ");
    scanf("%d", &vertices);
    if( vertices <= 0  || vertices > MAX_VERTICES){
        printf("Invalid number of vertices\n");
        return 1;
    }

    printf("Enter number of edges : ");
    scanf("%d", &edges);
    if( edges < 0  || edges >= (vertices*(vertices - 1 )/2)){
        printf("Invalid number of edges\n");
        return 1;
    }

    for(int i = 0 ; i < edges ;i++ ){
        printf("Enter the %d edge  (start, end) : ", i+1);
        scanf("%d %d" , &start , &end );
        if(start >= vertices || start < 0 || end >= vertices || end < 0 ){
            printf("Inavalid vertices . Try again\n");
            i--;
            continue;
        }
        addEdge(start, end);
    }
    detectSingleFailureNode();
}





























