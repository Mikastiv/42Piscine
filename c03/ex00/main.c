#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2);

int	main(void)
{
	printf("c: %d\n", strcmp("abcdef", "abcdef"));
	printf("ft: %d\n\n", ft_strcmp("abcdef", "abcdef"));
	printf("c: %d\n", strcmp("abcdef", ""));
	printf("ft: %d\n\n", ft_strcmp("abcdef", ""));
	printf("c: %d\n", strcmp("abcd", "abcdef"));
	printf("ft: %d\n\n", ft_strcmp("abcd", "abcdef"));
	printf("c: %d\n", strcmp("ABCDEF", "abcd"));
	printf("ft: %d\n\n", ft_strcmp("ABCDEF", "abcd"));
	printf("c: %d\n", strcmp("abcdef", "de"));
	printf("ft: %d\n\n", ft_strcmp("abcdef", "de"));
	printf("c: %d\n", strcmp("abcdef", "adef"));
	printf("ft: %d\n\n", ft_strcmp("abcdef", "adef"));
	printf("c: %d\n", strcmp("", "adef"));
	printf("ft: %d\n\n", ft_strcmp("", "adef"));
}
