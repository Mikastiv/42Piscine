#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(void)
{
	char buf[11];
	char *ret;
	int i;

	// Test 1
	ret = ft_strncpy(buf, "123456789\n", 11);
	printf("%s", buf);
	if (ret == buf)
		printf("%s", "OK!\n");
	else
		printf("%s", "KO!\n");
	// Test 2
	ret = ft_strncpy(buf, "1234567\n", 11);
	printf("%s", buf);
	if (buf[8] == '\0' && buf[9] == '\0' && buf[10] == '\0')
		printf("%s", "OK!\n");
	else
		printf("%s", "KO!\n");
	// Test 3
	ret = ft_strncpy(buf, "ABC", 3);
	if (buf[0] == 'A' && buf[1] == 'B' && buf[2] == 'C' && buf[3] == '4')
		printf("%s", "OK!\n");
	else
		printf("%s", "KO!\n");
	// Test 4
	ret = ft_strncpy(buf, "", 11);
	i = 0;
	while (i < 11)
	{
		if (buf[i] != '\0')
		{
			printf("%s", "KO!\n");
			return (0);
		}
		i++;
	}
	printf("%s", "OK!\n");
}
