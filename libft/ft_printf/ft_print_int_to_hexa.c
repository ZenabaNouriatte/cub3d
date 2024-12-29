/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_to_hexa.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:35:49 by lasablon          #+#    #+#             */
/*   Updated: 2024/06/04 11:44:52 by lasablon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int_to_hexa(unsigned int c, char *base, int result)
{
	if (c < 16)
	{
		write(1, &base[c], 1);
		result++;
	}
	else
	{
		result = ft_print_int_to_hexa(c / 16, base, result);
		result = ft_print_int_to_hexa(c % 16, base, result);
	}
	return (result);
}
