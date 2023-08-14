#include <stdio.h>

void main()
{
    int maxrange, numtracks, head;

    printf("Enter the number of tracks: ");
    scanf("%d", &numtracks);

    int tracks[numtracks + 2];
    int q[numtracks];

    printf("Enter the maxrange of the tracks: ");
    scanf("%d", &maxrange);

    printf("Enter the head: ");
    scanf("%d", &head);

    for (int i = 0; i < numtracks; i++)
    {
        printf("Enter the track to be traversed: ");
        scanf("%d", &q[i]);

        tracks[i] = q[i];
    }

    tracks[numtracks] = head;
    tracks[numtracks + 1] = maxrange;

    for (int i = 0; i < numtracks + 2; i++)
    {
        for (int j = 0; j < (numtracks + 2) - i - 1; j++)
        {
            if (tracks[j] > tracks[j + 1])
            {
                int temp = tracks[j];
                tracks[j] = tracks[j + 1];
                tracks[j + 1] = temp;
            }
        }
    }
    int headpos;
    for (int i = 0; i < numtracks + 2; i++)
    {
        if (tracks[i] == head)
        {
            headpos = i;
        }
    }
    for (int i = headpos; i < numtracks + 2; i++)
    {
        printf("%d => ", tracks[i]);
    }
    for (int i = headpos - 1; i >= 0; i--)
    {
        printf("%d => ", tracks[i]);
    }

    int tskt = (maxrange - head) + (maxrange - tracks[0]);
    printf("total seek time: %d", tskt);
}