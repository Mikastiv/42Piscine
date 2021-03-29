#include <unistd.h>

int	ft_strlen(char *str);

int	main(void)
{
	int len;

	len = ft_strlen("123456789");
	if (len == 9)
		write(1, "OK!", 3);
	else
		write(1, "KO!", 3);
}
