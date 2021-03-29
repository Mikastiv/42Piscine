#include <stdio.h>

char	*ft_strcpy(char *dest, char *src);

int	main(void)
{
	char	buf[11];
	char	*ret;

	ret = ft_strcpy(buf, "123456789\n");
	printf("%s", buf);
	if (ret == buf && buf[10] == '\0')
		printf("%s", "OK!\n");
	else
		printf("%s", "KO!\n");
}
