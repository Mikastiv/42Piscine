#include <stdio.h>

int	*ft_range(int min, int max);

int	main(void)
{
	int	*tab;
	int	i;

	tab = ft_range(0, 15);
	printf("%p\n", tab);
	i = 0;
	while (i <= 15)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
}
