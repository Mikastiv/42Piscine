#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_count_words(char *str, char *charset);
char **ft_split(char *str, char *charset);

int		main(void)
{
	int		index;
	char	**split;

	printf("count occ: %d\n", ft_count_words("kES49 lXGxtAAT9C 9JmrkI2zN       LkBprLQ", "FEKUeuW"));
	//split = ft_split("ImtmVrV6Ov8QrkGGUglBy7Vgsu iIsdl5XyT35Czv4xeu", "yenORYQ");
	split = ft_split("kES49 lXGxtAAT9C 9JmrkI2zN       LkBprLQ", "FEKUeuW");
	index = 0;
	printf("tab start\n");
	while (split[index])
	{
		printf("tab[%d]: $%s$\n", index, split[index]);
		fflush(stdout);
		index++;
	}
	printf("tab end\n");
}
