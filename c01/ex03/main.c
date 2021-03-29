#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int	main(void)
{
	int div;
	int mod;

	ft_div_mod(15, 10, &div, &mod);
	if (div == 15 / 10 && mod == 15 % 10)
		write(1, "OK!", 3);
	else
		write(1, "KO!", 3);
}
