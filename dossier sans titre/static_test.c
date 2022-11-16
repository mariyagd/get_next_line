#include <stdio.h>
#include "static.h"

void ft_patata()
{
    static t_patate j;

    if (j.i != 0)
        j.i = 0;
    printf("%d\n", ++(j.i));
}

int main()
{
    ft_patata();
    ft_patata();
    ft_patata();
    ft_patata();
    ft_patata();
}