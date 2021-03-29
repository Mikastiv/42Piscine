#include <stdio.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	main()
{
	printf("%s\n", ft_convert_base("      -2147483648", "0123456789", "0123456789ABCDEF"));
}
