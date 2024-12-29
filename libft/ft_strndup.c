/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmogne <zmogne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 23:18:26 by zmogne            #+#    #+#             */
/*   Updated: 2024/12/26 23:28:18 by zmogne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t strnlen(const char *s, size_t n)
{
	size_t i;

	i = 0;
	while (s[i] && i < n)
		i++;
	return (i);
}

char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	char	*new_str;

	len = strnlen(s, n);
	new_str = malloc(len + 1);
	if (new_str == NULL)
	{
		return (NULL);
	}
	ft_strncpy(new_str, s, len);
	new_str[len] = '\0';
	return (new_str);
}