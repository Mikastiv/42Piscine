#include <stdio.h>

char	*ft_strlowcase(char *str);

int	main(void)
{
	char	str[] = "abcedfghijklmnopqrstuvwxyz 0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZ \\/|!@#$%?&*()";
	char	*ret;

	ret = ft_strlowcase(str);
	printf("%s\n", str);
	printf("%s\n", ret);
	if (ret == str)
		printf("%s", "OK!\n");
	else
		printf("%s", "KO!\n");
}
