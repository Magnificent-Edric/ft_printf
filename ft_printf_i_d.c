/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:41:59 by medric            #+#    #+#             */
/*   Updated: 2021/12/04 17:41:59 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check(long int n)
{
	if (n >= 0)
		return (1);
	else
		return (-1);
}

static char	*putch(long int n, long int len, long int z, t_print *print)
{
	long int		i;
	char			*str;

	if ((n >= 0 && print->sign))
		len++;
	if (print->space && n >= 0 && !print->sign)
		len++;
	i = len;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (ft_check_malloc(print, str) == -1)
		return (NULL);
	if (print->is_precision == 1 && print->precision == 0 && n == 0)
		print->dot_zero = 1;
	if (str == 0)
		return (NULL);
	i--;
	str[i + 1] = '\0';
	while (len > 0)
	{
		str[i] = '0' + z * (n % 10);
		n = (n / 10);
		i--;
		len--;
	}
	return (str);
}

char	*print_i_d(int new, t_print *print)
{
	long int			newn;
	long int			z;
	long int			l;
	char				*str;

	str = NULL;
	newn = (long int)new;
	z = check(newn);
	l = len(newn);
	str = putch(newn, l, z, print);
	if (z < 0)
		str[0] = '-';
	else if (z > 0 && print->sign)
	{
		str[0] = '+';
	}
	else if (print->space && z > 0 && !print->sign)
	{
		str[0] = ' ';
	}
	return (str);
}
