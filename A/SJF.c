#include <stdio.h>
int main(){
	int bt[]={5,3,8,6};
	int n=4;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(bt[j]>bt[j+1]){
				int t=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=t;
			}
		}
	}
	int wt[n],tat[n];
	wt[0]=0;
	for(int i=1;i<n;i++){
		wt[i]=wt[i-1]+bt[i-1];
	}
	for(int i=0;i<n;i++){
		tat[i]=wt[i]+bt[i];
	}
	printf("PID\tWT\tBT\tTAT\n");
	for(int i=0;i<n;i++){
		printf("%d\t%d\t%d\t%d\n",i+1,wt[i],bt[i],tat[i]);
	}
}
