#include <stdio.h>

int	ft_str_is_alpha(char *str);

int	main(void)
{
	if (ft_str_is_alpha("abcdefghijklmnopqrstuvwxyz"))
		printf("%s", "OK!\n");
	else
		printf("%s", "KO!\n");
	if (ft_str_is_alpha("ABCDEFGHIJKLMNOPQRSTUVWXYZ"))
		printf("%s", "OK!\n");
	else
		printf("%s", "KO!\n");
	if (ft_str_is_alpha("0123456789"))
		printf("%s", "KO!\n");
	else
		printf("%s", "OK!\n");
	if (ft_str_is_alpha("Bad alpha string"))
		printf("%s", "KO!\n");
	else
		printf("%s", "OK!\n");
	if (ft_str_is_alpha("!@#$%?&*()_-+=~/<>,.;:[]^\\\'\""))
		printf("%s", "KO!\n");
	else
		printf("%s", "OK!\n");
}
