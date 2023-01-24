/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_input_spec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:25:12 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:25:12 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_input_spec(t_print *print)
{
	print->is_len += print->value_len;
	ft_putstr_len(print->specifier_value, print->value_len);
}
