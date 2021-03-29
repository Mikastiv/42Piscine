#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int	main(void)
{
	char str[21] = "0123";
	char	*rtn;

	rtn = strncat(str, "4567", 4);
	printf("%s\n", str);
	if (rtn == str && str[8] == '\0')
		printf("%s", "OK!\n");
	strcpy(str, "0123");
	rtn = ft_strncat(str, "4567", 4);
	printf("%s\n", str);
	if (rtn == str && str[8] == '\0')
		printf("%s", "OK!\n");

	strcpy(str, "0123");
	rtn = strncat(str, "4567", 2);
	printf("%s\n", str);
	if (rtn == str && str[6] == '\0')
		printf("%s", "OK!\n");
	strcpy(str, "0123");
	rtn = ft_strncat(str, "4567", 2);
	printf("%s\n", str);
	if (rtn == str && str[6] == '\0')
		printf("%s", "OK!\n");

	strcpy(str, "0123");
	rtn = strncat(str, "4567", 0);
	printf("%s\n", str);
	if (rtn == str)
		printf("%s", "OK!\n");
	strcpy(str, "0123");
	rtn = ft_strncat(str, "4567", 0);
	printf("%s\n", str);
	if (rtn == str)
		printf("%s", "OK!\n");

	strcpy(str, "0123");
	rtn = strncat(str, "4567", 7);
	printf("%s\n", str);
	if (rtn == str)
		printf("%s", "OK!\n");
	strcpy(str, "0123");
	rtn = ft_strncat(str, "4567", 7);
	printf("%s\n", str);
	if (rtn == str)
		printf("%s", "OK!\n");
}
