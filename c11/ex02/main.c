#include <stdio.h>

int	ft_any(char **tab, int(*f)(char*));
int	ft_has_letter(char *str)
{
	while (*str)
	{
		if (*str == '5')
			return (1);
		str++;
	}
	return (0);
}

int	main(void)
{
	char	*strs[5] = { "ABCDEF", "012345", "abcdefg5", "Salut", 0 };

	printf("%d\n", ft_any(strs, &ft_has_letter));
}