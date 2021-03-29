#include <unistd.h>

void	ft_ultimate_ft(int *********nbr);

int	main(void)
{
	int x;
	int *y;
	int **z;
	int ***a;
	int ****b;
	int *****c;
	int ******d;
	int *******e;
	int ********f;
	int *********g;

	x = 5384758;
	y = &x;
	z = &y;
	a = &z;
	b = &a;
	c = &b;
	d = &c;
	e = &d;
	f = &e;
	g = &f;
	ft_ultimate_ft(g);

	if (x == 42)
		write(1, "OK!", 3);
	else
		write(1, "KO!", 3);
}
