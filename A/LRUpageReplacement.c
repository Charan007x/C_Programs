// LRU pageReplacement

#include <stdio.h>
int main(){
	int page[50],frame[50],time[50];
	int n,f,i,j,k;
	int pageFaults=0,counter=0;
	printf("enter no. of pages\n");
	scanf("%d",&n);
	printf("enter the pages\n");
	for(i=0;i<n;i++) scanf("%d",&page[i]);
	printf("Enter no. of frames\n");
	scanf("%d",&f);
	for(i=0;i<f;i++){
		frame[i]=-1;
		time[i]=0;
	}
	
	for(i=0;i<n;i++){
		int found=-1;
		for(j=0;j<f;j++){
			if(frame[j]==page[i]){
				found=j;
				break;
			}
		}
		if(found!=-1){
			counter++;
			time[found]=counter;
		}else{
			int pos=0;
			for(j=1;j<f;j++){
				if(time[j]<time[pos]){
					pos=j;
				}
			}
			frame[pos]=page[i];
			counter++;
			time[pos]=counter;
			pageFaults++;
		}
	}
	printf("%d ",pageFaults);
		return 0;
}
