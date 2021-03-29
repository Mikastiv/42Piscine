#include <stdio.h>

char	*ft_strupcase(char *str);

int	main(void)
{
	char	str[] = "abcedfghijklmnopqrstuvwxyz 0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZ \\/|!@#$%?&*()[]-_=+";
	char	*ret;

	ret = ft_strupcase(str);
	printf("%s\n", str);
	printf("%s\n", ret);
	if (ret == str)
		printf("%s", "OK!\n");
	else
		printf("%s", "KO!\n");
}
