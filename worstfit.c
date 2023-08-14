#include <stdio.h>

void main()
{
    int blocknum, processnum;

    printf("Enter the number of blocks: ");
    scanf("%d", &blocknum);

    printf("Enter the number of process: ");
    scanf("%d", &processnum);

    int blockarr[blocknum], processarr[processnum], sortarr[blocknum];

    for (int i = 0; i < blocknum; i++)
    {
        printf("Enter the size of the memory blocks: ");
        scanf("%d", &blockarr[i]);
        sortarr[i] = blockarr[i];
    }

    for (int i = 0; i < processnum; i++)
    {
        printf("Enter the process: ");
        scanf("%d", &processarr[i]);
    }

    for (int i = 0; i < blocknum; i++)
    {
        for (int j = 0; j < blocknum - i - 1; j++)
        {
            if (sortarr[j] < sortarr[j + 1])
            {
                int temp = sortarr[j];
                sortarr[j] = sortarr[j + 1];
                sortarr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < processnum; i++)
    {
        int allocflag;
        for (int j = 0; j < blocknum; j++)
        {
            allocflag = 0;
            if (processarr[i] <= sortarr[j])
            {
                printf("process %d  in block of size %d\n", i + 1, sortarr[j]);
                sortarr[j] = 0;
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