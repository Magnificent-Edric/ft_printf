/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer_widht.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:23:06 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:23:06 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parcer_widht(char *format, t_print *print)
{
	int	r;

	r = 0;
	while ((format[r] >= 48 && format[r] <= 57))
		++r;
	print->is_widht = ft_substr(format, 0, r, print);
	return (r);
}
