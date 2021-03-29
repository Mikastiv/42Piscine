#include <stdio.h>

int	ft_atoi_base(char *str, char *base);

int	main(void)
{
	printf("%d\n", ft_atoi_base("rcrdmddd", "mrdoc"));
	printf("%d\n", ft_atoi_base("rcrdmddd", "mrdroc"));
	printf("%d\n", ft_atoi_base("  -rcrdmddd", "mrdoc"));
	printf("%d\n", ft_atoi_base("  --rcrdmddd", "mrdoc"));
	printf("%d\n", ft_atoi_base("  -++++rcrdmddd", "mrdoc"));
	printf("%d\n", ft_atoi_base("  -++++ rcrdmddd", "mrdoc"));
}
