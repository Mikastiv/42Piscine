#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src);

int	main(void)
{
	char str[21] = "0123";
	char	*rtn;

	rtn = strcat(str, "4567");
	printf("%s\n", str);
	if (rtn == str && str[8] == '\0')
		printf("%s", "OK!\n");
	strcpy(str, "0123");
	rtn = ft_strcat(str, "4567");
	printf("%s\n", str);
	if (rtn == str && str[8] == '\0')
		printf("%s", "OK!\n");
}
