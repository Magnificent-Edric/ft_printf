/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_i_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:47:54 by medric            #+#    #+#             */
/*   Updated: 2021/12/04 17:47:54 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_specifier_i_d(t_print *print, va_list arg)
{
	if (print->specifier == 'i' || print->specifier == 'd')
		print->specifier_value = print_i_d(va_arg(arg, int), print);
	if (print->specifier_value == NULL)
		print->value_len = 0;
	else
		print->value_len = ft_strlen(print->specifier_value);
}
