/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:55:21 by lasablon          #+#    #+#             */
/*   Updated: 2025/01/24 11:01:29 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **tab)
{
	size_t	i;

	if (!tab)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
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
		return (NULL);
	result = ft_calloc((ft_wordcount(str, c) + 1), sizeof(char *));
	if (!result)
		return (NULL);
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
				return (ft_free(result), NULL);
		}
		else
			str++;
	}
	return (result);
}
