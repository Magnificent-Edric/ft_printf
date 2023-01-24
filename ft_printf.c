/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:19:14 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:19:14 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	t_print	print;
	char	*str;

	str = (char *)format;
	if (format == NULL)
		return (-1);
	va_start(arg, format);
	ft_init_print(&print);
	ft_read_file(&print, arg, str);
	ft_strdel(&print.specifier_value);
	va_end(arg);
	return (print.is_len);
}
