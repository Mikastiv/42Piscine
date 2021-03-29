#include <stdio.h>

int	ft_is_sort(int *tab, int length, int(*f)(int, int));

int	ft_difference(int a, int b)
{
	return (a - b);
}

int	main(void)
{
	int	tab[13] = {-5, -4, -4, 0, 1, 2, 2, 3, 4, 5, 6, 7, 8};

	printf("%d\n", ft_is_sort(tab, 0, &ft_difference));
}