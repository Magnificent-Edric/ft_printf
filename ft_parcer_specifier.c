/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:23:15 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:23:15 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parser_spnnarg(va_list arg, char *symbol, t_print *print, int *i)
{
	if (symbol[*i] == 'x')
	{
		print->specifier = symbol[*i];
		++(*i);
		ft_specifier_lower_x(print, arg);
	}
	else if (symbol[*i] == 'X')
	{
		print->specifier = symbol[*i];
		++(*i);
		ft_specifier_upper_x(print, arg);
	}
	else if (symbol[*i] == 'p')
	{
		print->specifier = symbol[*i];
		++(*i);
		ft_specifier_p_address(print, arg);
	}
	else if (symbol[*i] == '%')
	{
		print->specifier = symbol[*i];
		++(*i);
		print->hash = 1;
	}
	return (*i);
}

static int	ft_parser_sp_n_a(va_list arg, char *symbol, t_print *print, int *i)
{
	if (symbol[*i] == 'u')
	{
		print->specifier = symbol[*i];
		++(*i);
		ft_specifier_u(print, arg);
	}
	else if (symbol[*i] == 'i' || symbol[*i] == 'd')
	{
		print->specifier = symbol[*i];
		++(*i);
		ft_specifier_i_d(print, arg);
	}
	else
		(*i) = ft_parser_spnnarg(arg, symbol, print, i);
	return (*i);
}

int	ft_parse_specifier(va_list arg, char *symbol, t_print *print)
{
	int	i;

	i = 0;
	if (symbol[i] == 'c')
	{
		print->specifier = symbol[i];
		++i;
		ft_specifier_c(print, arg);
	}
	else if (symbol[i] == 's')
	{
		print->specifier = symbol[i];
		++i;
		ft_specifier_s(print, arg);
	}
	else
		i = ft_parser_sp_n_a(arg, symbol, print, &i);
	return (i);
}
