/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_res0_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:21:27 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:21:27 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_print(t_print *print)
{
	print->is_widht = 0;
	print->is_precision = 0;
	print->precision = 0;
	print->null = 0;
	print->is_zero = 0;
	print->sign = 0;
	print->is_len = 0;
	print->is_minus = 0;
	print->hash = 0;
	print->space = 0;
	print->specifier_value = NULL;
	print->specifier = 0;
	print->value_len = 0;
	print->dot_zero = 0;
	print->error = 0;
	return ;
}

void	rem_init(t_print *print)
{
	print->is_widht = 0;
	print->is_precision = 0;
	print->precision = 0;
	print->is_zero = 0;
	print->is_minus = 0;
	print->null = 0;
	print->hash = 0;
	print->space = 0;
	print->sign = 0;
	ft_strdel(&print->specifier_value);
	print->specifier_value = NULL;
	print->specifier = 0;
	print->value_len = 0;
	print->dot_zero = 0;
	return ;
}
