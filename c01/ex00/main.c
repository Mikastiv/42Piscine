#include <unistd.h>

void	ft_ft(int *nbr);

int	main(void)
{
	int x;

	x = 456345345;
	ft_ft(&x);
	if (x == 42)
		write(1, "OK!", 3);
	else
		write(1, "KO!", 3);
}
