#include <stdio.h>
#define ARR_SIZE 10

void	ft_sort_int_tab(int *tab, int size);

int	main(void)
{
	int arr[ARR_SIZE] = { 0, 234, 9, 5, 134, 2, 7345543, 84, 3345345, 433 };
	int i;

	ft_sort_int_tab(arr, ARR_SIZE);
	i = 0;
	while (i < ARR_SIZE)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("%s", "\n");
}
