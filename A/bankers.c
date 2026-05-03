#include <stdio.h>

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    int a[n][m], mx[n][m], av[m], need[n][m], f[n];

    // input
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&mx[i][j]);

    for(int j=0;j<m;j++)
        scanf("%d",&av[j]);

    // need & finish
    for(int i=0;i<n;i++){
        f[i]=0;
        for(int j=0;j<m;j++)
            need[i][j]=mx[i][j]-a[i][j];
    }

    // main logic
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            if(!f[i]){
                int ok=1;
                for(int j=0;j<m;j++)
                    if(need[i][j]>av[j]) ok=0;

                if(ok){
                    for(int j=0;j<m;j++)
                        av[j]+=a[i][j];
                    f[i]=1;
                }
            }
        }
    }

    // check
    for(int i=0;i<n;i++){
        if(!f[i]){
            printf("Not Safe");
            return 0;
        }
    }

    printf("Safe");
}
