#include <stdio.h>

int	ft_count_words(char *str, char *charset);
char	**ft_split(char *str, char *charset);

int	main(void)
{
	char	**split = ft_split(",,,,,,", ",");
	int i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
}
