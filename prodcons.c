#include <stdio.h>

int wait(int n);
int signal(int n);

void producer();
void consumer();

int mutex = 1, full = 0, empty = 0, x = 0;

void main()
{
    while (1)
    {
        printf("1.producer 2.cons 3.exit");

        int choice;
        scanf("%d", &choice);

        if (choice == 1)
        {
            if (mutex == 1 && full != 3)
            {
                producer();
            }
            else
            {
                printf("Buffer is full");
            }
        }
        else if (choice == 2)
        {
            if (mutex == 1 && empty != 0)
            {
                consumer();
            }
            else
            {
                printf("Buffer is empty");
            }
        }
        else if (choice == 3)
        {
            return;
        }
    }
}

int wait(int s)
{
    return (--s);
}
int signal(int s)
{
    return (++s);
}

void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("produced %d", x);
    mutex = signal(mutex);
}

void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    x--;
    printf("consumed %d", x);
    mutex = signal(mutex);
}