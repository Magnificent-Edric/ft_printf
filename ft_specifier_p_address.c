/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_p_address.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:21:04 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:21:04 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_str(char *str)
{
	int	flg;

	if (!str)
		flg = 1;
	else
		flg = 0;
	return (flg);
}

void	secret_case2(t_print *print, char*str)
{
	if (print->specifier == 'p')
	{
		if (ft_str(str) == 1)
			print->null = 1;
		else
			print->null = 0;
	}
	return ;
}

void	ft_specifier_p_address(t_print *print, va_list arg)
{
	if (print->specifier == 'p')
		print->specifier_value = printad(va_arg(arg, unsigned long int), print);
	if (print->specifier_value == NULL)
		print->value_len = 0;
	else
		print->value_len = ft_strlen(print->specifier_value);
	secret_case2(print, print->specifier_value);
}
