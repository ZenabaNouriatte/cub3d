/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:45:30 by lasablon          #+#    #+#             */
/*   Updated: 2024/05/28 15:13:30 by lasablon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_chars(long n)
{
	long	count;

	count = 0;
	if (n == 0)
		return (2);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count + 1);
}

static char	*ft_reverse_output(char *str, long size)
{
	int	start;
	int	end;
	int	temp;

	start = 0;
	end = size - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		end--;
		start++;
	}
	return (str);
}

static void	ft_handle_neg(long *min, long *n)
{
	if (*n < 0)
	{
		*n = -*n;
		*min = -1;
	}
}

static char	*ft_handle_zero(long n, char *str)
{
	if (n == 0)
	{
		str[0] = 0 + '0';
		str[1] = '\0';
		return (str);
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long	i;
	long	min;
	char	*str;
	long	nb;

	i = 0;
	min = 1;
	nb = (long)n;
	str = malloc(sizeof(char) * ft_count_chars(nb));
	if (!str)
		return (NULL);
	if (nb == 0)
		return (ft_handle_zero(nb, str));
	ft_handle_neg(&min, &nb);
	while (nb > 0)
	{
		str[i++] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (min == -1)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_reverse_output(str, i));
}
