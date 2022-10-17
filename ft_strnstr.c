#include "libft.h"

static size_t	min(size_t x, size_t y)
{
	if (x <= y)
		return (x);
	return (y);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;
	size_t	i;

	len_needle = ft_strlen(needle);
	if (!len_needle)
		return ((char *)haystack);
	if (haystack == NULL && len == 0)
		return (NULL);
	len = min(len, ft_strlen(haystack));
	i = 0;
	while (i + len_needle <= len)
	{
		if (ft_strncmp(&haystack[i], needle, len_needle) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
