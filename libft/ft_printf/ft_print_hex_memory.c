/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_memory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:36:04 by lasablon          #+#    #+#             */
/*   Updated: 2024/06/04 11:39:55 by lasablon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_memory(void *ptr, char *base, int result)
{
	uintptr_t	c;

	c = (uintptr_t)ptr;
	if (c == 0 && result == 0)
	{
		ft_modded_putstr("(nil)");
		return (5);
	}
	if (result == 0)
	{
		write(1, "0x", 2);
		result += 2;
	}
	if (c < 16)
	{
		write(1, &base[c], 1);
		result++;
	}
	else
	{
		result = ft_print_hex_memory(((void *)(c / 16)), base, result);
		result = ft_print_hex_memory(((void *)(c % 16)), base, result);
	}
	return (result);
}
