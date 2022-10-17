#include "libft.h"

static size_t	count_words(char const *lp, char c)
{
	char const	*rp;
	size_t		words;

	rp = lp;
	words = 0;
	while (*rp != '\0')
	{
		while (*rp == c)
		{
			lp++;
			rp++;
		}
		while (*rp != c && *rp != '\0')
			rp++;
		if (lp != rp)
		{
			words++;
			lp = rp;
		}
	}
	return (words);
}

static char	*ft_strndup(char const *src, size_t size)
{
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (size + 1));
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, src, size + 1);
	return (dst);
}

static unsigned int	set_split_str(char const *lp, char c, char **list)
{
	char const	*rp;
	size_t		i;

	rp = lp;
	i = 0;
	while (*rp != '\0')
	{
		while (*rp == c)
		{
			lp++;
			rp++;
		}
		while (*rp != c && *rp != '\0')
			rp++;
		if (lp != rp)
		{
			list[i] = ft_strndup(lp, rp - lp);
			if (list[i] == NULL)
				return (0);
			i++;
			lp = rp;
		}
	}
	return (1);
}

static void	free_all(char **list)
{
	size_t	i;

	i = 0;
	while (list[i] != NULL)
	{
		free(list[i]);
		i++;
	}
	free(list);
}

char	**ft_split(char const *s, char c)
{
	size_t	list_size;
	char	**list;

	if (s == NULL)
		return (NULL);
	list_size = count_words(s, c);
	list = (char **)malloc(sizeof(char *) * (list_size + 1));
	if (list == NULL)
		return (NULL);
	if (set_split_str(s, c, list))
	{
		list[list_size] = NULL;
		return (list);
	}
	free_all(list);
	return (NULL);
}

// #include <stdio.h>

// void put_s(char **s)
// {
// 	while (*s)
// 	{
// 		printf("%s\n", *s);
// 		s++;
// 	}
// 	printf("-----\n");
// }

// int main(void)
// {
// 	put_s(ft_split("///aaa////aa//", '/'));
// 	put_s(ft_split("///bbb////bb", '/'));

// 	put_s(ft_split("cc////c//cccc", '/'));
// 	put_s(ft_split("ddd////d//", '/'));
// 	put_s(ft_split("ee//e//eee", '/'));
// 	put_s(ft_split("fff", '/'));
// 	put_s(ft_split("gg", '\0'));

// 	return (0);
// }
