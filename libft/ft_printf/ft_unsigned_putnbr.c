/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:37:03 by lasablon          #+#    #+#             */
/*   Updated: 2024/06/04 11:37:07 by lasablon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_putnbr(unsigned int n, int result)
{
	if (n < 10)
	{
		ft_modded_putchar(n + '0');
		result++;
	}
	else
	{
		result = ft_unsigned_putnbr(n / 10, result);
		result = ft_unsigned_putnbr(n % 10, result);
	}
	return (result);
}
