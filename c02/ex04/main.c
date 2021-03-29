#include <stdio.h>

int	ft_str_is_lowercase(char *str);

int	main(void)
{
	if (ft_str_is_lowercase("abcdefghijklmnopqrstuvwxyz"))
		printf("%s", "OK!\n");
	else
		printf("%s", "KO!\n");
	if (!ft_str_is_lowercase("A"))
		printf("%s", "OK!\n");
	else
		printf("%s", "KO!\n");
	if (ft_str_is_lowercase("z"))
		printf("%s", "OK!\n");
	else
		printf("%s", "KO!\n");
	if (!ft_str_is_lowercase("0123456ASDasdasAJGr@#$#!9"))
		printf("%s", "OK!\n");
	else
		printf("%s", "KO!\n");
}
