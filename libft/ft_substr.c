/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:02:46 by lasablon          #+#    #+#             */
/*   Updated: 2025/01/31 16:39:30 by lasablon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	y;
	char	*new;

	i = start;
	y = 0;
	if (start > ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (len >= ft_strlen(&s[start]))
		new = malloc((ft_strlen(&s[start]) + 1) * sizeof(char));
	else
		new = malloc(((len + 1) * sizeof(char)));
	if (!new)
		return (NULL);
	while (y < len && s[i])
		new[y++] = s[i++];
	new[y] = '\0';
	return (new);
}
