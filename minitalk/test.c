#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// void handle()
// {
//     printf("welcome , your signal received successfully !!\n");
// }
// void ft_print_bits(unsigned char octet)
// {
//     int i = 0;
//     char c;
//     while (i < 8)
//     {
//        c = ((octet >> i) & 1) + 48;
//        write(1, &c, 1);
//        i++;
//     }
// }
void swap(unsigned int octet)
{
    char c = ((octet >> 4) | (octet << 4));
    write (1, &c, 1);
}

int main()
{
   swap(4);
    // 00000111
}