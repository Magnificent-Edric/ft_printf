/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer_minus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:23:43 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:23:43 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parcer_minus(char *format, t_print *print)
{
	int	r;
	int	m;

	r = 0;
	while (format[r] != '-')
		r++;
	while (format[r] == '-')
		r++;
	m = r;
	while ((format[r] >= 48 && format[r] <= 57))
		r++;
	print->is_minus = ft_substr(format, m, r, print);
	print->is_zero = 0;
	return (r);
}
