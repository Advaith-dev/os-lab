#include <stdio.h>

void main()
{
    int refseqnum, framenum, pagefault = 0;

    printf("Enter the number of pages in ref seq: ");
    scanf("%d", &refseqnum);

    printf("Enter the number of frames: ");
    scanf("%d", &framenum);

    int frame[framenum], refseq[refseqnum];

    for (int i = 0; i < framenum; i++)
    {
        frame[i] = -1;
    }

    for (int i = 0; i < refseqnum; i++)
    {
        printf("Enter the page ref: ");
        scanf("%d", &refseq[i]);
    }
    int nextalloc = 0;
    for (int i = 0; i < refseqnum; i++)
    {
        int hit = 0;
        for (int j = 0; j < framenum; j++)
        {
            if (refseq[i] == frame[j])
            {
                printf("HIT");
                hit = 1;
                break;
            }
        }
        if (hit == 0)
        {
            pagefault += 1;
            frame[nextalloc] = refseq[i];
            nextalloc = (nextalloc + 1) % framenum;
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
    printf("PAGE FAULT = %d", pagefault);
}
