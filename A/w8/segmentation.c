#include <stdio.h>

int main() {
    int base[3], limit[3], s, off;

    for(int i=0;i<3;i++)
        scanf("%d %d", &base[i], &limit[i]);

    scanf("%d %d", &s, &off);

    if(off < limit[s])
        printf("Physical Address = %d", base[s] + off);
    else
        printf("Invalid address");
}
