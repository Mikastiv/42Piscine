#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b);

int main(void)
{
	int a;
	int b;

	a = 10;
	b = 3;
	ft_ultimate_div_mod(&a, &b);
	if (a == 10 / 3 && b == 10 % 3)
		write(1, "OK!", 3);
	else
		write(1, "KO!", 3);
}
