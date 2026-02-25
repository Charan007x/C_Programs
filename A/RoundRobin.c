#include <stdio.h>
int main(){
	int bt[]={5,3,1};
	int n=3;
	int wt[n],rem[n];
	int tq=2;
	int time=0;
	for(int i=0;i<n;i++){
		rem[i]=bt[i];
	}
	while(1){
		int done=1;
		for(int i=0;i<n;i++){
			if(rem[i]>0){
				done=0;
				if(rem[i]>tq){
				time+=tq;
				rem[i]-=tq;
			}else{
				time+=rem[i];
				wt[i]=time-bt[i];
				rem[i]=0;
			}
			}
		}
		if(done==1) break;
	}
	printf("PID\tWT\tBT\n");
	for(int i=0;i<n;i++){
		printf("%d\t%d\t%d\n",i+1,wt[i],bt[i]);
	}
}
