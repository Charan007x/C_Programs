#include <stdio.h>
int main(){
	int bt[]={5,3,8};
	int pr[]={2,1,3};
	int n=3;
	int wt[3],tat[3];
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(pr[i]>pr[j]){
				int t;
				t=pr[i];
				pr[i]=pr[j];
				pr[j]=t;
				
				t=bt[i];
				bt[i]=bt[j];
				bt[j]=t;
			}
		}
	}
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
