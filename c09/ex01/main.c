#include <stdio.h>

#include "includes/ft.h"

int main(void)
{
	int x = 42;
	int y = 21;

	ft_putchar('0');
	ft_putchar('\n');
	ft_swap(&x, &y);
	printf("X: %d Y: %d\n", x, y);
	ft_putstr("Hello World!\n");
	printf("Len: %d %s\n", ft_strlen("Bonjour"), "Bonjour");
	printf("Cmp: %d\n", ft_strcmp("123545", "12354455"));
	printf("Cmp: %d\n", ft_strcmp("12354", "12354455"));
	printf("Cmp: %d\n", ft_strcmp("12354", "12354"));
}