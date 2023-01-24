/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:23:34 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:23:34 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parcer_null(char *format, t_print *print)
{
	int	r;

	r = 1;
	while ((format[r] >= 48 && format[r] <= 57))
		++r;
	print->is_zero = ft_substr(format, 0, r, print);
	return (r);
}
