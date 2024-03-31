#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int len = -1;

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s;

	s = b;
	while (len--)
	{
		*(unsigned char *)s++ = (unsigned char)c;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	bytes;
	void	*p;
    int i;

    i = 0;
	bytes = count * size;
	if (size && bytes / size != count)
		return (NULL);
	p = malloc(bytes);
	if (p == NULL)
		return (NULL);
    ft_memset(p, 0, bytes);
	return (p);
}

void handle(int client_bit)
{
    static int c;
    static int count = 7;
    static char *string;
    static int i;

    if(client_bit == SIGUSR1)
        c |= ((1 << count));
    count--;
    if (count < 0)
    {
        // c += 48;
        if (len == -1)
        {
            len = c;
            string = ft_calloc (len * sizeof(char) , 1);
        }
        else
        {
            string[i] = (char)c;
            i++;
            if(ft_strlen(string) == len)
            {
                write(1, string, ft_strlen(string));
                free(string);
                string = NULL;
                len = -1;
                i = 0;
            }
        }
        count = 7;
        c = 0;
    }
    usleep (500);
}
int main()
{
    printf("i am a server\n");
    printf("my pid is : %d\n", getpid());
    sigaction(SIGUSR1, &handle, NULL);
    sigaction(SIGUSR2, &handle, NULL);
    // write (1, "dd\n", 3);
    while (1)
    {
        
        pause ();
    }
}