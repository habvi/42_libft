#include "libft.h"

static unsigned int	is_space(int c)
{
	return (c == '\t' || c == '\n' || c == '\v' || \
			c == '\f' || c == '\r' || c == ' ');
}

static unsigned int	is_operator(int c)
{
	return (c == '-' || c == '+');
}

static unsigned int	is_overflow(size_t num, int c, int op)
{
	size_t	ov_div;
	size_t	ov_mod;

	ov_div = LONG_MAX / 10;
	ov_mod = LONG_MAX % 10 + (op == -1);
	if (num > ov_div)
		return (1);
	if (num == ov_div && (size_t)c - '0' > ov_mod)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	num;
	int		op;

	num = 0;
	op = 1;
	while (is_space(*str))
		str++;
	if (is_operator(*str))
	{
		op -= 2 * (*str == '-');
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (is_overflow(num, *str, op))
		{
			if (op == 1)
				return ((int)LONG_MAX);
			else
				return ((int)LONG_MIN);
		}
		num = num * 10 + *str - '0';
		str++;
	}
	return ((int)(num * op));
}
