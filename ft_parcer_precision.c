/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:23:24 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:23:24 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parser_precision(char *format, int *p, t_print *print)
{
	int	r;

	r = 0;
	while ((format[r] >= '0' && format[r] <= '9'))
		r++;
	*p = ft_substr(format, 0, r, print);
	return (r);
}
