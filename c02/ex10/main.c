#include <stdio.h>

#define BUF_SIZE 10

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int	main(void)
{
	char	buf[BUF_SIZE];
	char	buf1[10];
	int		res;

	// Test 1
	res = ft_strlcpy(buf, "123456789", BUF_SIZE);
	printf("%s\n", buf);
	if (res == 9 && buf[9] == '\0')
		printf("%s", "OK!\n");
	else
		printf("%s", "KO!\n");
	// Test 2
	res = ft_strlcpy(buf, "12345", BUF_SIZE);
	printf("%s\n", buf);
	if (res == 5 && buf[5] == '\0')
		printf("%s", "OK!\n");
	else
		printf("%s", "KO!\n");
	// Test 3
	buf1[0] = '6';
	res = ft_strlcpy(buf1, "12345", 0);
	if (res == 5 && buf1[0] == '6')
		printf("%s", "OK!\n");
	else
		printf("%s", "KO!\n");
	res = ft_strlcpy(buf1, "12345", 1);
	if (res == 5 && buf1[0] == '\0')
		printf("%s", "OK!\n");
	else
		printf("%s", "KO!\n");
}
