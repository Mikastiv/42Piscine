#include <stdio.h>

int	ft_is_prime(int nb);

int main(void)
{
	int i = 0;

	while (i < 500)
	{
		if (ft_is_prime(i))
			printf("%d\n", i);
		i++;
	}
}
