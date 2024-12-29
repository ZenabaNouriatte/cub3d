/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:55:21 by lasablon          #+#    #+#             */
/*   Updated: 2024/12/27 13:01:19 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

static int	ft_wordcount(const char *str, char c)
{
	int	wordcount;
	int	sep;

	wordcount = 0;
	sep = 0;
	while (*str)
	{
		if (*str != c && sep == 0)
		{
			sep = 1;
			wordcount++;
		}
		else if (*str == c)
			sep = 0;
		str++;
	}
	return (wordcount);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	int		j;
	char	**result;

	if (!str)
		return (0);
	result = ft_calloc((ft_wordcount(str, c) + 1), sizeof(char *));
	if (!result)
		return (0);
	i = 0;
	while (*str)
	{
		if (*str != c)
		{
			j = 0;
			while ((*str) && (*str != c) && (++j))
				str++;
			result[i] = ft_substr(str - j, 0, j);
			if (!result[i++])
				return (ft_free(result));
		}
		else
			str++;
	}
	return (result);
}
