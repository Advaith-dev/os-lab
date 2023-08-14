#include <stdio.h>

void main()
{
    int processnum, resnum;

    printf("Enter the number of processes: ");
    scanf("%d", &processnum);

    printf("Enter the number of resources: ");
    scanf("%d", &resnum);

    int alloc[processnum][resnum], max[processnum][resnum], available[resnum];

    int f[processnum], ans[processnum], need[processnum][resnum], ind = 0;

    printf("max value: ");

    for (int i = 0; i < processnum; i++)
    {
        for (int j = 0; j < resnum; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("allocation value: ");

    for (int i = 0; i < processnum; i++)
    {
        for (int j = 0; j < resnum; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("available value: ");

    for (int j = 0; j < resnum; j++)
    {
        scanf("%d", &available[j]);
    }

    for (int j = 0; j < processnum; j++)
    {
        f[j] = 0;
    }

    for (int i = 0; i < processnum; i++)
    {
        for (int j = 0; j < resnum; j++)
        {
            need[i][j] = max[i][j] = alloc[i][j];
        }
    }
    for (int i = 0; i < processnum; i++)
    {
        for (int j = 0; j < processnum; j++)
        {
            if (f[j] == 0)
            {
                int flag = 0;
                for (int k = 0; k < resnum; k++)
                {
                    if (need[j][k] > available[k])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (int t = 0; t < resnum; t++)
                    {
                        available[t] = available[t] + alloc[j][t];
                    }
                    f[j] = 1;
                }
            }
        }
    }
    printf("The safe seq: \n");
    for (int i = 0; i < processnum - 1; i++)
    {
        printf("P%d->", ans[i]);
    }
    printf("p%d", ans[processnum - 1]);
}