#include <unistd.h>

void	ft_swap(int *a, int *b);

int	main(void)
{
	int x;
	int y;

	x = 42;
	y = 66;
	ft_swap(&x, &y);

	if (x == 66 && y == 42)
		write(1, "OK!", 3);
	else
		write(1, "KO!", 3);
}
