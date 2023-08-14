#include <stdio.h>

void main()
{
    int blocknum, processnum;

    printf("Enter the number of blocks: ");
    scanf("%d", &blocknum);

    printf("Enter the number of process: ");
    scanf("%d", &processnum);

    int blockarr[blocknum], processarr[processnum];

    for (int i = 0; i < blocknum; i++)
    {
        printf("Enter the size of the memory blocks: ");
        scanf("%d", &blockarr[i]);
    }

    for (int i = 0; i < processnum; i++)
    {
        printf("Enter the process: ");
        scanf("%d", &processarr[i]);
    }
    for (int i = 0; i < processnum; i++)
    {
        int allocflag;
        for (int j = 0; j < blocknum; j++)
        {
            allocflag = 0;
            if (processarr[i] <= blockarr[j])
            {
                printf("process %d  block %d\n", i + 1, j + 1);
                blockarr[j] = 0;
                allocflag = 1;
                break;
            }
        }
        if (allocflag == 0)
        {
            printf("process %d cannot be allocated\n", i + 1);
        }
    }
}