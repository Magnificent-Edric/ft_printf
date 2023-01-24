/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widht.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:19:27 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:19:27 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_widht(char *format, t_print *print)
{
	int	i;

	i = 0;
	if ((format[i] >= 48 && format[i] <= 57))
		i += ft_parcer_widht(format, print);
	return (i);
}
