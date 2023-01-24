/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:23:51 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:23:51 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parser_flag_zero(char *format, t_print *print)
{
	int	i;

	i = 0;
	if ((format[i] >= 48 && format[i] <= 57))
		i += ft_parcer_null(format, print);
	return (i);
}
