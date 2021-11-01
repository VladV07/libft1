/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stapioca <stapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:20:15 by stapioca          #+#    #+#             */
/*   Updated: 2021/10/26 20:33:55 by stapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static long int	col_word(char const *s, char c)
{
	unsigned int	i;
	unsigned int	col_w;

	i = 0;
	col_w = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			break ;
		col_w++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (col_w);
}

static unsigned int	size_world(char const *s, char c)
{
	unsigned int	size_w;

	size_w = 0;
	while (s[size_w] != c && s[size_w] != '\0')
	{
		size_w++;
	}
	return (size_w);
}

static char	**s_to_str(char const *s, char **str, char c, unsigned int	t)
{
	unsigned int	i;
	unsigned int	j;
	long int		k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i] != c && s[i] != '\0')
		{
			str[k][j] = s[i];
			j++;
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				str[k][j] = '\0';
				k++;
			}
			i++;
		}
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	str[t] = NULL;
	return (str);
}

static char	**do_split(char const *s, char c, char **str, unsigned int col_w)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	size_w;

	i = 0;
	j = 0;
	size_w = 0;
	while (j < col_w)
	{
		i = i + size_w;
		while (s[i] == c && s[i] != '\0')
			i++;
		size_w = size_world(&s[i], c);
		str[j] = (char *)malloc(sizeof(char) * size_w + 1);
		if (str[j] == NULL)
		{
			while (j-- >= 0)
				free(str[j]);
			free(str);
			return (NULL);
		}
		j++;
	}
	str = s_to_str(s, str, c, j);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	col_w;
	char			**str;

	if (s == NULL)
		return (NULL);
	col_w = col_word(s, c);
	str = (char **)malloc(sizeof(char *) * col_w + 1);
	if (str == NULL)
		return (NULL);
	str = do_split(s, c, str, col_w);
	return (str);
}
