#include "libft.h"

static size_t	count_length(long num, size_t now)
{
	if (!num)
		return (now);
	return (count_length(num / 10, now + 1));
}

static char	*set_to_list(long num, size_t len, int is_minus)
{
	char	*res;
	size_t	i;

	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[len - i - 1] = num % 10 + '0';
		num /= 10;
		i++;
	}
	if (is_minus)
		res[0] = '-';
	res[len] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	size_t	num;
	size_t	len;
	int		is_minus;

	is_minus = 0;
	len = 0;
	if (n < 0)
	{
		is_minus = 1;
		len++;
		if (n == INT_MIN)
			num = (size_t)(-(n + 1)) + 1;
		else
			num = -n;
	}
	else
		num = n;
	len += count_length(num, 0);
	if (n == 0)
		len = 1;
	return (set_to_list(num, len, is_minus));
}
