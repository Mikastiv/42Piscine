#include <stdio.h>

char	*ft_strcapitalize(char *str);

int		main(void)
{
	char	str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	char	*ret;

	ret = ft_strcapitalize(str);
	printf("%s\n", str);
	printf("%s\n", ret);
	if (str == ret)
		printf("%s", "OK!\n");
	else
		printf("%s", "KO!\n");
	char str1[] = "une belle#$#phrase@%$?%&*??& en minuscule";
	ret = ft_strcapitalize(str1);
	printf("%s\n", str1);
	printf("%s\n", ret);
	char str2[] = "une 42belle#$#8phRAse@%$?%&*??& aVec des MAJUSCULES";
	ret = ft_strcapitalize(str2);
	printf("%s\n", str2);
	printf("%s\n", ret);
}
