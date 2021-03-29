#include <stdio.h>

void	ft_putnbr_base(int nbr, char *base);

int	main(void)
{
	ft_putnbr_base(0xFAA33CC, "01");
	printf("\n");
	ft_putnbr_base(0xFAA33CC, "0123456789ABCDEF");
	printf("\n");
	ft_putnbr_base(188385, "onjrBu");
	printf("\n");
}
