#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(void)
{
	printf("c: %d\n", strncmp("abc", "abc", 3));
	printf("ft: %d\n\n", ft_strncmp("abc", "abc", 3));
	printf("c: %d\n", strncmp("abc", "abcdef", 3));
	printf("ft: %d\n\n", ft_strncmp("abc", "abcdef", 3));
	printf("c: %d\n", strncmp("abc", "", 3));
	printf("ft: %d\n\n", ft_strncmp("abc", "", 3));
	printf("c: %d\n", strncmp("", "", 3));
	printf("ft: %d\n\n", ft_strncmp("", "", 3));
	printf("c: %d\n", strncmp("abcdef", "de", 3));
	printf("ft: %d\n\n", ft_strncmp("abcdef", "de", 3));
	printf("c: %d\n", strncmp("abcdef", "de", 4));
	printf("ft: %d\n\n", ft_strncmp("abcdef", "de", 4));
	printf("c: %d\n", strncmp("abcdef", "de", 10));
	printf("ft: %d\n\n", ft_strncmp("abcdef", "de", 10));
	printf("c: %d\n", strncmp("abcdef", "de", 0));
	printf("ft: %d\n\n", ft_strncmp("abcdef", "de", 0));
}
