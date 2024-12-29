/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:19:28 by lasablon          #+#    #+#             */
/*   Updated: 2024/07/29 18:34:54 by lasablon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_handle_conversions(format[i], args);
			if (format[i] == '\0')
				return (count);
		}
		else
			count += ft_modded_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	ft_printf("%X", -42);
// 	return (0);
// }