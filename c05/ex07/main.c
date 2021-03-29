#include <stdio.h>

int	ft_find_next_prime(int nb);

int main(void)
{
	printf("%d\n", ft_find_next_prime(-23));
	printf("%d\n", ft_find_next_prime(4));
	printf("%d\n", ft_find_next_prime(11));
	printf("%d\n", ft_find_next_prime(49));
	printf("%d\n", ft_find_next_prime(500));
}
