#include <stdio.h>

void main()
{
    int refseqnum, framenum, pagefault = 0;

    printf("Enter the number of pages in ref seq: ");
    scanf("%d", &refseqnum);

    printf("Enter the number of frames: ");
    scanf("%d", &framenum);

    int frame[framenum], refseq[refseqnum], frameclone[framenum];

    for (int i = 0; i < framenum; i++)
    {
        frame[i] = -1;
    }

    for (int i = 0; i < refseqnum; i++)
    {
        printf("Enter the page ref: ");
        scanf("%d", &refseq[i]);
    }

    for (int i = 0; i < refseqnum; i++)
    {
        int hit = 0;

        for (int j = 0; j < framenum; j++)
        {
            if (refseq[i] == frame[j])
            {
                hit = 1;
                printf("HIT");
                break;
            }
        }
        if (hit == 0)
        {
            pagefault += 1;
            int lastvalue;
            if (pagefault > framenum)
            {
                int frameclone[framenum];
                for (int q = 0; q < framenum; q++)
                {
                    frameclone[q] = frame[q];
                }

                for (int t = i - 1; t >= 0; t--)
                {
                    for (int m = 0; m < framenum; m++)
                    {
                        if (refseq[t] == frameclone[m])
                        {
                            lastvalue = refseq[t];
                            frameclone[m] = -1;
                        }
                    }
                }
                printf("lru: %d", lastvalue);
                for (int r = 0; r < framenum; r++)
                {
                    if (frame[r] == lastvalue)
                    {
                        frame[r] = refseq[i];
                    }
                }
            }
            else
            {
                frame[pagefault - 1] = refseq[i];
            }
            printf("for %d: ", refseq[i]);
            for (int k = 0; k < framenum; k++)
            {
                if (frame[k] == -1)
                {
                    break;
                }
                printf("%d ", frame[k]);
            }
        }
        printf("\n");
    }
}
