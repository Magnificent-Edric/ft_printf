/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:21:17 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:21:17 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_specifier_c(t_print *print, va_list arg)
{
	char	c;

	c = (unsigned char)va_arg(arg, int);
	if (print->specifier == 'c')
		print->specifier_value = print_char(c, print);
	if (print->specifier_value == NULL)
		print->value_len = 0;
	else
		print->value_len = ft_strlen(print->specifier_value);
}
