#include <stdio.h>

int	ft_count_if(char **tab, int length, int(*f)(char*));

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

int main(void)
{
	char	*strs[4] = { "ABCDEF", "012345", "abcdefg5", "Salut" };

	printf("%d\n", ft_count_if(strs, 4, &ft_has_letter));
}