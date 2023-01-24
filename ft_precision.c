/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:22:57 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:22:57 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_precision(char *format, t_print *print)
{
	int	i;

	i = 0;
	if (format[i] == '.')
	{
		++i;
		print->is_precision = 1;
		i += parser_precision((format + i), &print->precision, print);
	}
	else
	{
		print->is_precision = 0;
		print->precision = 0;
	}
	return (i);
}
