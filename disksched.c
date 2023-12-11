// FCFS

#include <stdio.h>

void main()
{
    int headpos, tracks, maxrange;

    printf("Enter the number of tracks: ");
    scanf("%d", &tracks);

    printf("Enter the headposition: ");
    scanf("%d", &headpos);

    printf("Enter the maximum range of the disk: ");
    scanf("%d", &maxrange);

    int trackarr[tracks];
    int req[tracks];

    for (int i = 0; i < tracks; i++)
    {
        printf("Enter the track to be traversed: ");
        scanf("%d", &trackarr[i]);
        req[i] = trackarr[i];
    }

    printf("%d =>", headpos);
    int totalskt = 0;

    for (int i = 0; i < tracks; i++)
    {
        int temp;
        if (i < tracks - 1)
        {
            printf("%d =>", req[i]);
            temp = req[i] - req[i + 1];
            if (temp < 0)
            {
                temp *= -1;
            }
            totalskt += temp;
        }
        else
        {
            printf("%d", req[tracks - 1]);
        }
    }
    totalskt = totalskt + (headpos - req[0]);
    printf("\nTotal seek time: %d", totalskt);
}