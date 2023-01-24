/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:52:50 by medric            #+#    #+#             */
/*   Updated: 2021/12/04 16:52:50 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_next3_input(t_print *print)
{
	if (print->specifier == 'X')
	{
		if (print->is_precision)
			format_precision(print);
		if (print->is_minus)
			format_minus(print);
		else if (print->is_zero)
			format_zero(print);
		if (print->is_widht)
			format_widht_ch_str(print);
	}
	else if (print->specifier == 'p')
	{
		if (print->is_minus)
			format_minus(print);
		if (print->is_widht)
			format_widht_ch_str(print);
	}
}

static void	ft_next_next_input(t_print *print)
{
	if (print->specifier == 'x')
	{
		if (print->is_precision)
			format_precision(print);
		if (print->is_minus)
			format_minus(print);
		else if (print->is_zero)
			format_zero(print);
		if (print->is_widht)
			format_widht_ch_str(print);
	}
	else
		ft_next3_input(print);
}

static void	ft_next_input(t_print *print)
{
	if (print->specifier == 'u')
	{
		if (print->is_precision)
			format_precision(print);
		if (print->is_minus)
			format_minus(print);
		else if (print->is_zero)
			format_zero(print);
		format_widht_ch_str(print);
	}
	else if (print->specifier == 's')
	{
		if (print->is_precision)
			format_precision(print);
		if (print->is_minus)
			format_minus(print);
		format_widht_ch_str(print);
	}
	else
		ft_next_next_input(print);
}

int	input(t_print *print)
{
	if (print->specifier == '\0')
		return (0);
	else if (print->specifier == 'c')
	{
		if (print->is_minus)
			format_minus(print);
		format_widht_ch_str(print);
	}
	else if (print->specifier == 'd' || print->specifier == 'i')
	{
		if (print->is_precision)
			format_precision(print);
		if (print->is_minus)
			format_minus(print);
		if (print->is_zero)
			format_zero(print);
		if (print->is_widht)
			format_widht_num(print);
	}
	else
		ft_next_input(print);
	format_input_spec(print);
	return (0);
}
