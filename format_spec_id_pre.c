/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_spec_id_pre.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:38:52 by medric            #+#    #+#             */
/*   Updated: 2021/12/12 14:30:12 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	format_id_next_pr(t_print *print)
{
	if (print->dot_zero == 1 && print->is_minus == 0)
		print->is_len += 0;
	if (print->is_widht != 0 && print->dot_zero == 1
		&& print->is_minus == 0)
	{
		print->is_len += print->is_widht;
		while (print->is_widht > 0)
		{
			write(1, " ", 1);
			print->is_widht--;
		}
	}
}

void	format_id_precision(t_print *print)
{
	if (ft_strlen(print->specifier_value) == 1)
	{
		if (print->dot_zero == 1 && print->is_minus != 0)
		{
			print->is_len += print->is_minus;
			while (print->is_minus > 0 || print->is_zero > 0)
			{
				write(1, " ", 1);
				print->is_minus--;
			}
		}
		if (print->dot_zero == 1 && print->is_minus == 0 && print->is_zero != 0)
		{
			print->is_len += print->is_zero;
			while (print->is_zero > 0)
			{
				write(1, " ", 1);
				print->is_zero--;
			}
		}
		format_id_next_pr(print);
	}
	return ;
}
