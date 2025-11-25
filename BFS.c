#include <stdio.h>
#include <stdlib.h>
#define max 5
void BFS(int start,int a[max][max]){
	int visited[max]={0};
	int queue[max];
	int front=0,rear=0;
	visited[start]=1;
	queue[rear++]=start;
	while(front<rear){
		int u=queue[front++];
		printf("%d ",u);
		for(int v=0;v<max;v++){
			if(a[u][v]==1&&!visited[v]){
				visited[v]=1;
				queue[rear++]=v;
			}
		}
	}
	printf("\n");
}
int main() {
    // 0-based indexing adjacency matrix
    int a[max][max] = {
        {0, 1, 1, 0, 0},  // 0 connected to 1,2
        {1, 0, 1, 1, 0},  // 1 connected to 0,2,3
        {1, 1, 0, 1, 0},  // 2 connected to 0,1,3
        {0, 1, 1, 0, 1},  // 3 connected to 1,2,4
        {0, 0, 0, 1, 0}   // 4 connected to 3
    };
    BFS(0,a);    
    return 0;
}
