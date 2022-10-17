#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*pd;
	const unsigned char	*ps;
	size_t				i;

	pd = (unsigned char *)dst;
	ps = (const unsigned char *)src;
	if (pd == ps)
		return (dst);
	i = 0;
	while (i < n)
	{
		pd[i] = ps[i];
		i++;
	}
	return (dst);
}
