// FCFS pageReplacement

#include <stdio.h>
int main(){
int page[50],frame[20];
int n,f,i,j,k,pos;
int pageFaults=0,index=0,found;
printf("Enter no. of pages\n");
scanf("%d",&n);
printf("Enter page reference strings\n");
for(i=0;i<n;i++) scanf("%d",&page[i]);
printf("Enter no of frames\n");
scanf("%d",&f);
for(i=0;i<f;i++) frame[i]=-1;

for(i=0;i<n;i++){
	found=0;
	for(j=0;j<f;j++){
		if(frame[j]==page[i]){
			found=1;
			break;
		}
	}
	if(found==0){
		frame[index]=page[i];
		index=(index+1)%f;
		pageFaults++;
	}
}
printf("Total pageFaults is %d",pageFaults);
return 0;
}
