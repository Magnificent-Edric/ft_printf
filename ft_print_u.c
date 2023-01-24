/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:22:21 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:22:21 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*putch_u(long int n, long int l, t_print *print)
{
	long int		i;
	char			*str;

	i = l;
	str = (char *)malloc(sizeof(char) * (l + 1));
	if (ft_check_malloc(print, str) == -1)
		return (NULL);
	if (str == 0)
		return (NULL);
	i--;
	str[i + 1] = '\0';
	while (l > 0)
	{
		str[i] = '0' + (n % 10);
		n = (n / 10);
		i--;
		l--;
	}
	return (str);
}

static int	anmud2(t_print *print, unsigned int new)
{
	if (new == 0 && print->precision == 0
		&& print->is_precision == 1 && print->is_widht > 0)
	{
		print->is_len += print->is_widht;
		while (print->is_widht > 0)
		{
			write(1, " ", 1);
			print->is_widht--;
		}
		return (1);
	}
	else
		return (0);
}

static int	anmud(t_print *print, unsigned int new)
{
	if (new == 0 && print->precision == 0
		&& print->is_precision == 1 && print->is_zero > 0)
	{
		print->is_len += print->is_zero;
		while (print->is_zero > 0)
		{
			write(1, " ", 1);
			print->is_zero--;
		}
		return (1);
	}
	else
		return (0);
}

char	*ft_print_ud(unsigned int new, t_print *print)
{
	int					l;
	char				*str;

	l = len(new);
	if (new == 0 && print->precision == 0 && print->is_widht == 0
		&& print->is_precision == 1 && print->is_zero == 0)
	{
		str = NULL;
		print->is_len += 0;
		return (str);
	}
	if (anmud(print, new) == 1)
		return (NULL);
	if (anmud2(print, new) == 1)
		return (NULL);
	str = putch_u(new, l, print);
	return (str);
}
