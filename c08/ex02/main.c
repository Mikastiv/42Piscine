#include "ft_abs.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	printf("%d\n", ABS(-INT_MAX));
	printf("%d\n", ABS(INT_MAX));
	printf("%d\n", ABS(0));
}