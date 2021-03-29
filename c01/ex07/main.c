#include <stdio.h>
#define ARR_SIZE 10

void	ft_rev_int_tab(int *tab, int size);

int	main(void)
{
	int arr[ARR_SIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 823423, 9234233 };
	int i;

	ft_rev_int_tab(arr, ARR_SIZE);
	i = 0;
	while (i < ARR_SIZE)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("%s", "\n");
}
