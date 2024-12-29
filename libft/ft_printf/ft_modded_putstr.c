/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modded_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:38:44 by lasablon          #+#    #+#             */
/*   Updated: 2024/06/04 11:38:47 by lasablon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_modded_putstr(char *s)
{
	int	count;

	if (s == NULL)
		return (ft_modded_putstr("(null)"));
	count = ft_strlen(s);
	write(1, s, count);
	return (count);
}
