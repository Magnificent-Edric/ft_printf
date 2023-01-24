/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_solve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:19:40 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:19:40 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_solve(va_list arg, char *format, t_print *print)
{
	int	i;

	i = 0;
	i += ft_parcer_flags((format + i), print);
	i += ft_widht((format + i), print);
	i += ft_precision((format + i), print);
	i += ft_parse_specifier(arg, (format + i), print);
	return (i);
}
