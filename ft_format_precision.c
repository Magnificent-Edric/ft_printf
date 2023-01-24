/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:24:57 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:24:57 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_precision(t_print *print)
{
	if (print->specifier == 'i' || print->specifier == 'd')
		print->specifier_value = ft_format_p_id(print, &print->precision);
	if (print->specifier == 'x' || print->specifier == 'X')
		print->specifier_value = ft_format_p_ux_lx(print, &print->precision);
	if (print->specifier == 's')
		print->specifier_value = ft_format_p_s(print, &print->precision);
	if (print->specifier == 'u')
		print->specifier_value = ft_format_p_u(print, &print->precision);
}
