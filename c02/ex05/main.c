#include <stdio.h>

int	ft_str_is_uppercase(char *str);

int	main(void)
{
	if (ft_str_is_uppercase("ABCDEFGHIJKLMNOPQRSTUVWXYZ"))
		printf("%s", "OK!\n");
	else
		printf("%s", "KO!\n");
	if (ft_str_is_uppercase("Z"))
		printf("%s", "OK!\n");
	else
		printf("%s", "KO!\n");
	if (!ft_str_is_uppercase("a"))
		printf("%s", "OK!\n");
	else
		printf("%s", "KO!\n");
	if (!ft_str_is_uppercase("ABDFASASD\\/|!@#$%?&*()[]-_=+'\",.<>~¨^`"))
		printf("%s", "OK!\n");
	else
		printf("%s", "KO!\n");
}
