#include "libft.h"

void	*ft_memchr(const void *s, int int_c, size_t n)
{
	const unsigned char	*ps;
	unsigned char		c;
	size_t				i;

	ps = (const unsigned char *)s;
	c = (unsigned char)int_c;
	i = 0;
	while (i < n)
	{
		if (ps[i] == c)
			return ((void *)&ps[i]);
		i++;
	}
	return (NULL);
}
