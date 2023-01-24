/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:25:20 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:25:20 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_next(char *format, t_print *print, int *i)
{
	if (format[*i] == ' ')
	{
		(*i)++;
		while (format[*i] == ' ')
			(*i)++;
		print->space = 1;
	}
	else if (format[*i] == '#')
	{
		(*i)++;
		print->hash = 1;
	}
}

int	ft_parcer_flags(char *format, t_print *print)
{
	int	i;

	i = 0;
	if (format[i] == '0')
		i += ft_parcer_null(format, print);
	if (format[i] == '-')
		i += ft_parcer_minus((format + i), print);
	else if (format[i] == '+')
	{
		i++;
		while (format[i] == '+')
			i++;
		print->sign = 1;
	}
	else
		ft_next(format, print, &i);
	return (i);
}
