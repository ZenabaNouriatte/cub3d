/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:59:35 by lasablon          #+#    #+#             */
/*   Updated: 2024/12/23 14:33:33 by lasablon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>

int	ft_print_int_to_hexa(unsigned int c, char *base, int result);
int	ft_print_hex_memory(void *ptr, char *base, int result);
int	ft_modded_putchar(char c);
int	ft_modded_putnbr(int n, int result);
int	ft_modded_putstr(char *s);
int	ft_unsigned_putnbr(unsigned int n, int result);
int	ft_handle_conversions(char option, va_list args);
int	ft_printf(const char *format, ...);
#endif
