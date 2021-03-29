#include <stdio.h>

void	ft_putstr_non_printable(char *str);

int	main(void)
{
	char	str[32];
	int		i;

	i = 0;
	while (i < 32 - 1)
	{
		str[i] = i + 1;
		i++;
	}
	str[31] = '\0';
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
	printf("%s\n", "");
	ft_putstr_non_printable(str);
	printf("%s\n", "");
}
