#include <stdio.h>

int	ft_is_sort(int *tab, int length, int(*f)(int, int));

int	ft_difference(int a, int b)
{
	return (a - b);
}

int	main(void)
{
	int	tab[26] = {7, 7, 7, 7, 6, 6, 6, 6, 5, 5, 4, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 1, 1, 1};

	printf("%d\n", ft_is_sort(tab, 26, &ft_difference));
}