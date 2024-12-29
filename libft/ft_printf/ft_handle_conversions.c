/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_conversions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:35:34 by lasablon          #+#    #+#             */
/*   Updated: 2024/06/04 11:35:37 by lasablon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_conversions(char option, va_list args)
{
	if (option == 'c')
		return (ft_modded_putchar(va_arg(args, int)));
	if (option == 's')
		return (ft_modded_putstr(va_arg(args, char *)));
	if (option == 'i' || option == 'd')
		return (ft_modded_putnbr(va_arg(args, int), 0));
	if (option == 'u')
		return (ft_unsigned_putnbr(va_arg(args, unsigned int), 0));
	if (option == 'x')
		return (ft_print_int_to_hexa(va_arg(args, int), "0123456789abcdef", 0));
	if (option == 'X')
		return (ft_print_int_to_hexa(va_arg(args, int), "0123456789ABCDEF", 0));
	if (option == '%')
		return (ft_modded_putchar('%'));
	if (option == 'p')
		return (ft_print_hex_memory(va_arg(args, void *), "0123456789abcdef",
				0));
	return (0);
}
