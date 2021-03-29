#include <stdio.h>

int	ft_str_is_numeric(char *str);

int	main(void)
{
	if (ft_str_is_numeric("0123456789"))
		printf("%s", "OK!\n");
	else
		printf("%s", "KO!\n");
	if (!ft_str_is_numeric("0123456ASDasdasAJGr@#$#!9"))
		printf("%s", "OK!\n");
	else
		printf("%s", "KO!\n");
}
