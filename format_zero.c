/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:25:48 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:25:48 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_zero(t_print *print)
{
	if (print->is_zero > print->value_len)
	{
		if (print->is_zero > print->value_len
			&& print->is_zero < print->precision)
		{
			print->specifier_value = ft_format(print, '0', &print->is_zero);
			print->value_len = print->is_zero;
		}
		else if (print->is_zero > print->value_len
			&& print->is_zero > print->precision && print->precision != 0)
		{
			print->specifier_value = ft_format(print, ' ', &print->is_zero);
			print->value_len = print->is_zero;
		}
		else
		{
			print->specifier_value = ft_format(print, '0', &print->is_zero);
			print->value_len = print->is_zero;
		}
	}
	return ;
}
