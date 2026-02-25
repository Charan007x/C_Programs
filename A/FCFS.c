#include <stdio.h>
int main(){
	int bt[]={5,3,8,6};
	int n=4;
	int wt[4],tat[4];
	wt[0]=0;
	for(int i=1;i<4;i++){
		wt[i]=wt[i-1]+bt[i-1];
	}
	for(int i=0;i<n;i++){
		tat[i]=bt[i]+wt[i];
	}
	printf("PID\tWT\tBT\tTAT\n");
	for(int i=0;i<n;i++){
		printf("%d\t%d\t%d\t%d\n",i+1,wt[i],bt[i],tat[i]);
	}
}
