#include <stdio.h>

void	*ft_print_memory(void *addr, unsigned int size);

int	main(void)
{
	void	*ret;
	char	*mem = "Bonjour les aminches\t\n\tc  est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";
	ret = ft_print_memory((void*)mem, 92);
	if (mem == ret)
		printf("%s", "OK!\n");
	else
		printf("%s", "KO!\n");
}
