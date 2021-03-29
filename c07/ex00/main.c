#include <stdio.h>

char	*ft_strdup(char *src);

int	main(void)
{
	char	*str;

	str = ft_strdup("Hello World!");
	printf("%s\n", str);
}
