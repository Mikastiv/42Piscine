#include <stdio.h>
#include <stdlib.h>

void	ft_foreach(int *tab, int length, void(*f)(int));
int		*ft_map(int *tab, int length, int(*f)(int));

void	ft_putnbr(int nbr)
{
	printf("%d\n", nbr);
}

int	ft_mul(int nbr)
{
	return (nbr * 2);
}

int	main(void)
{
	int	tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
	int *tab2 = ft_map(tab, 20, &ft_mul);

	ft_foreach(tab2, 20, &ft_putnbr);
	free(tab2);
}
