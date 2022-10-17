#include "libft.h"

static unsigned int	ft_islower(int c)
{
	return ('a' <= c && c <= 'z');
}

static unsigned int	ft_isupper(int c)
{
	return ('A' <= c && c <= 'Z');
}

int	ft_isalpha(int c)
{
	return (ft_islower(c) || ft_isupper(c));
}
