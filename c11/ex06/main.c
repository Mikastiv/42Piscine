#include <stdio.h>

void	ft_sort_string_tab(char **tab);

int	main(void)
{
	char	*tab[] = { "12345", "4322", "123", "abcs", "nbhas", "ABdsds", 0};
	ft_sort_string_tab(tab);

	int		i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}