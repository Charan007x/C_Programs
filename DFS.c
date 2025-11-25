#include <stdio.h>
#include <stdlib.h>
#define max 5
void DFS(int start,int a[max][max]){
	int visited[max]={0};
	int stack[max];
	int top=-1;
	stack[++top]=start;
	while(top!=-1){
		int u=stack[top--];
		if(!visited[u]){
			printf("%d ",u);
			visited[u]=1;
			for(int v=max-1;v>=0;v--){
				if(a[u][v]==1&&!visited[v]){
					stack[++top]=v;
				}
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
    DFS(0,a);    
    return 0;
}
