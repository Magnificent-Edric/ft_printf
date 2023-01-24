/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_null_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:47:27 by medric            #+#    #+#             */
/*   Updated: 2021/12/07 20:00:17 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_null_str(t_print *print)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = "(null)";
	print->specifier_value = (char *)malloc(sizeof(char) * (7));
	ft_check_malloc(print, print->specifier_value);
	while (s2[i] != '\0')
	{
		print->specifier_value[i] = s2[i];
		i++;
	}
	print->specifier_value[i] = '\0';
	print->value_len = ft_strlen(print->specifier_value);
	if (print->is_precision)
		format_precision(print);
	if (print->is_minus)
		format_minus(print);
	format_widht_ch_str(print);
	format_input_spec(print);
	return ;
}
