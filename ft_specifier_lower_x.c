/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_lower_x.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:21:10 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:21:10 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_specifier_lower_x(t_print *print, va_list arg)
{
	if (print->specifier == 'x')
		print->specifier_value = ft_print_l_x(va_arg(arg, unsigned int), print);
	if (print->specifier_value == NULL)
		print->value_len = 0;
	else
		print->value_len = ft_strlen(print->specifier_value);
}
