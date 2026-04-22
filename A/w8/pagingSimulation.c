#include <stdio.h>

int main()
{
    int pageSize, logicalAddress;
    int pageNumber, offset;

    printf("Enter page size: ");
    scanf("%d", &pageSize);

    printf("Enter logical address: ");
    scanf("%d", &logicalAddress);

    pageNumber = logicalAddress / pageSize;
    offset = logicalAddress % pageSize;

    printf("Page Number = %d\n", pageNumber);
    printf("Offset = %d\n", offset);

    return 0;
}
