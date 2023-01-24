/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:20:53 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:20:53 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_case_s(char	*str)
{
	int	flg;

	if (!str)
		flg = 1;
	else
		flg = 0;
	return (flg);
}

static void	secret_case_s(t_print *print, char *str)
{
	if (print->specifier == 's')
	{
		if (ft_case_s(str) == 1)
			print->null = 1;
		else
			print->null = 0;
	}
}

void	ft_specifier_s(t_print *print, va_list arg)
{
	char	*str;

	str = va_arg(arg, char *);
	if (print->specifier == 's' && str != NULL)
		print->specifier_value = print_string(str, print);
	if (print->specifier_value == NULL)
		print->value_len = 0;
	else
		print->value_len = ft_strlen(print->specifier_value);
	secret_case_s(print, print->specifier_value);
}
