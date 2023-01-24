/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diff_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:25:29 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:25:29 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_sharp_n(t_print *print, char c)
{
	if (print->is_zero)
	{
		print->is_len += print->is_zero;
		while (print->is_zero > 1)
		{
			write(1, "0", 1);
			print->is_zero--;
		}
		write(1, &c, 1);
		print->is_len++;
		return (1);
	}
	else
		return (0);
}

static int	format_sh_n(t_print *print, char c)
{
	if (print->is_minus != 0)
	{
		write(1, &c, 1);
		print->is_len += print->is_minus;
		while (print->is_minus > 1)
		{
			write(1, " ", 1);
			print->is_minus--;
		}
		print->is_len++;
		return (1);
	}
	else
		return (0);
}

void	format_hash(t_print *print)
{
	char	c;

	c = '%';
	print->is_len += print->is_widht;
	while (print->is_widht > 1)
	{
		write(1, " ", 1);
		print->is_widht--;
	}
	if (format_sh_n(print, c) == 1)
		return ;
	if (format_sharp_n(print, c) == 1)
		return ;
	write(1, &c, 1);
	print->is_len++;
	return ;
}

void	format_null_pointer(t_print *print)
{
	if (print->is_widht <= 3)
	{
		write(1, "0x0", 3);
		print->is_len += 3;
		return ;
	}
	if (print->is_widht > 3)
	{
		print->is_widht = print->is_widht - 3;
		print->is_len += print->is_widht;
		while (print->is_widht > 0)
		{
			write(1, " ", 1);
			print->is_widht--;
		}
		write(1, "0x0", 3);
		print->is_len += 3;
	}
	return ;
}

int	diff_format(t_print *print)
{
	if (print->specifier == 's' && print->null)
		format_null_str(print);
	else if (print->specifier == '%' && print->hash)
		format_hash(print);
	else if (print->specifier == 'p' && print->null)
		format_null_pointer(print);
	else if ((print->specifier == 'i' || print->specifier == 'd')
		&& print->dot_zero == 1 && print->precision == 0)
		format_id_precision(print);
	else
		input(print);
	return (0);
}
