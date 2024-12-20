#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES] = {0} ;
int visited[MAX_VERTICES] = {0};
int vertices;
int edges;

void addEdge(int start, int end){
    graph[start][end] = 1;
    graph[end][start] = 1;
}

int isCycleUtil(int currentVertex, int parent){
    visited[currentVertex] = 1 ;
    for( int i=0 ; i< vertices ; i++){
        if(graph[currentVertex][i] == 1){
            if(!visited[i]){
                if(isCycleUtil( i ,currentVertex)){
                    return 1;
                }
            }
            else if( i!= parent){
                return 1;
            }
        }
    }
    return 0;
}



int isCyclic(){
    for(int i=0 ; i<vertices ; i++){
        visited[vertices] = 0;
    }
    for(int i=0 ; i<vertices ; i++){
        if(!visited[i] && isCycleUtil(i, -1) ){
            return 1;
        }
    }
    return 0;

}


int main(){
    int start,end;

    printf("Enter the number of vertices : ");
    scanf("%d", &vertices);
    if( vertices <= 0 || vertices > MAX_VERTICES ){
        printf("Invalid number of vertices .");
        return 1;
    }

    printf("Enter the number of edges :");
    scanf("%d", &edges);

    if( edges < 0 || edges >= (vertices*(vertices-1)/2)){
        printf("Invalid number of edges. Exiting...");
        return 1 ;
    }

    for(int i=0 ; i < edges ; i++){
        printf("Enter the %d edge (start, end) :", i+1);
        scanf("%d %d" , &start, &end);
        if(start < 0 || start >= vertices  || end < 0 || end >= vertices ){
            printf("Invalid edge . try again\n");
            i--;
            continue;
        }
        addEdge(start, end);
    }
    if(isCyclic()){
        printf("Cycle is present in a graph\n");
    }
    else{
        printf("Cycle does not present in a graph");
    }
    return 0;

}
