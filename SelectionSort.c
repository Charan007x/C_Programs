#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n-1;i++){
		int min_idx=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[min_idx]){
				min_idx=j;
			}
		}
		int t=a[i];
		a[i]=a[min_idx];
		a[min_idx]=t;
	}
	for(int i=0;i<n;i++) printf("%d ",a[i]);
}
