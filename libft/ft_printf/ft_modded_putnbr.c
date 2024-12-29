/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modded_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:36:41 by lasablon          #+#    #+#             */
/*   Updated: 2024/06/04 11:36:47 by lasablon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_modded_putnbr(int n, int result)
{
	if (n == -2147483648)
	{
		ft_modded_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		ft_modded_putchar('-');
		result++;
		n = -n;
	}
	if (n < 10)
	{
		ft_modded_putchar(n + '0');
		result++;
	}
	else
	{
		result = ft_modded_putnbr(n / 10, result);
		result = ft_modded_putnbr(n % 10, result);
	}
	return (result);
}
