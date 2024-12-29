/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:04:01 by lasablon          #+#    #+#             */
/*   Updated: 2024/05/25 16:04:50 by lasablon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int searchedChar)
{
	size_t	i;

	i = ft_strlen(str);
	while (str[i] != (unsigned char)searchedChar && i > 0)
		i--;
	if (str[i] == (unsigned char)searchedChar)
		return ((char *)str + i);
	return (NULL);
}
