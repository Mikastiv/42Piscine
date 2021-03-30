#include <stdio.h>

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *));

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	main(void)
{
	char	*tab[] = { "g2pILl3a69jC", "1pvWFX8NjxJT", "sL8GPQJ", "71", "l", "6ceSKr4lihx", "iPF6MHzhdVt", "5OHAdDTR", "7nqXJ68Z2", "lOUkFA8Sb", 0};
	ft_advanced_sort_string_tab(tab, &ft_strcmp);

	int		i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}