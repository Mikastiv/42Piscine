#include <stdio.h>

void ft_putchar(char c);
void ft_swap(int *a, int *b);
void ft_putstr(char *str);
int ft_strlen(char *str);
int ft_strcmp(char *s1, char *s2);

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
	printf("Cmp: %d\n", ft_strcmp("12351", "12354455"));
	printf("Cmp: %d\n", ft_strcmp("12359", "12354455"));
	printf("Cmp: %d\n", ft_strcmp("12354", "12354"));
}