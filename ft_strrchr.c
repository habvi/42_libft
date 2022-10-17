#include "libft.h"

char	*ft_strrchr(const char *s, int int_c)
{
	char		c;
	const char	*res;

	c = (char)int_c;
	res = NULL;
	while (*s)
	{
		if (*s == c)
			res = s;
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return ((char *)res);
}
