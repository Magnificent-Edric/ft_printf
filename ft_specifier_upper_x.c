/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_upper_x.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:20:37 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:20:37 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_specifier_upper_x(t_print *print, va_list arg)
{
	if (print->specifier == 'X')
		print->specifier_value = print_upp_x(va_arg(arg, unsigned int), print);
	if (print->specifier_value == NULL)
		print->value_len = 0;
	else
		print->value_len = ft_strlen(print->specifier_value);
}
