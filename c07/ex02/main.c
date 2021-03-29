#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max);

int	main(void)
{
	int	*tab;
	int len;
	int	i;

	len = ft_ultimate_range(&tab, 0, 15);
	printf("%p\n", &tab);
	i = 0;
	while (i <= 15)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
}
