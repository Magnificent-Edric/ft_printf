/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:21:37 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:21:37 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	error(t_print *print)
{
	print->is_len = -1;
	write(1, "-1", 2);
}

void	ft_read_file(t_print *print, va_list arg, char *format)
{
	size_t	i;
	int		res;

	i = 0;
	while (format[i] && print->error == 0)
	{
		if (format[i] == '%')
		{
			++i;
			rem_init(print);
			i += type_solve(arg, (format + i), print);
			if (diff_format(print))
				return ;
		}
		res = 0;
		while (format[i] != '%' && format[i])
		{
			++print->is_len;
			++res;
			++i;
		}
		ft_putstr_len((format + i - res), res);
	}
	if (print->error == -1)
		error(print);
}
