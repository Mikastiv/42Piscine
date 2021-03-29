#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int	ft_atoi(char *str);

int	main(void)
{
	int	ret;

	// Test 0
	ret = ft_atoi("-2147483648");
	printf("%d\n", ret);

	// Test 1
	char	str[] = {9, 10, 11, 12, 13, 32, 32, 13, 11, 11, '-', '-', '+', '-', '+', '1', '2', '7'};
	ret = ft_atoi(str);
	printf("%d\n", ret);
}
