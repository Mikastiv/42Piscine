#include <stdio.h>

int	ft_str_is_printable(char *str);

int	main(void)
{
	char str[] = "A";
	char c = ' ';

	while (c <= '~')
	{
		str[0] = c;
		if (!ft_str_is_printable(str))
			break ;
		c++;
	}
	if (c == '~' + 1)
		printf("%s", "OK!\n");
	else
		printf("%s", "KO!\n");
}
