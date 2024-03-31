#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void handle(int client_bit)
{
    static int c;
    static int count = 7;
    char x;
    if(client_bit == SIGUSR1)
        c |= ((1 << count));
    count--;
    if (count < 0)
    {
        // c += 48;
        x = (char)c;
        write (1, &x, 1);
        count = 7;
        c = 0;
    }
    usleep (500);
}
int main()
{
    printf("i am a server\n");
    printf("my pid is : %d\n", getpid());
    signal(SIGUSR1, handle);
    signal(SIGUSR2, handle);
    // write (1, "dd\n", 3);
    while (1)
    {
        
        pause ();
    }

    // handle (0);
    // handle (1);
    // handle (0);
    // handle (0);
    // handle (0);
    // handle (0);
    // handle (0);
    // handle (1);
}