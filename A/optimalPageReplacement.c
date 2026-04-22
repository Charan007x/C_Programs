// optimal 

#include <stdio.h>
int main(){
    int page[50], frame[50];
    int n,f,i,j,k;
    int pageFault=0;

    printf("enter no. of pages\n");
    scanf("%d",&n);

    printf("Enter the pages\n");
    for(i=0;i<n;i++) scanf("%d",&page[i]);

    printf("Enter no of frames\n");
    scanf("%d",&f);

    for(i=0;i<f;i++) frame[i]=-1;

    for(i=0;i<n;i++){

        int found=0;

        for(j=0;j<f;j++){
            if(frame[j]==page[i]){
                found=1;
                break;
            }
        }

        if(found==0){

            int pos=0,farthest=i;

            for(j=0;j<f;j++){

                for(k=i+1;k<n;k++){
                    if(frame[j]==page[k]){
                        break;
                    }
                }

                if(k==n){
                    pos=j;
                    break;
                }

                if(k>farthest){
                    farthest=k;
                    pos=j;
                }
            }

            frame[pos]=page[i];
            pageFault++;
        }
    }

    printf("%d",pageFault);

    return 0;
}
