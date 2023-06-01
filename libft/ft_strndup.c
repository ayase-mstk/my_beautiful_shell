#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*str;
	size_t	i;

	str = malloc(sizeof(char) * (n + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (*s && i < n)
		str[i++] = *s++;
	str[i] = '\0';
	return (str);
}
