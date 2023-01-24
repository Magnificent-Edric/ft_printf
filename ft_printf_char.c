/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:38:28 by medric            #+#    #+#             */
/*   Updated: 2021/12/04 17:38:28 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

static int	checkker(char c, t_print *print)
{
	if (c == '\0' && print->is_minus == 0)
	{
		if (print->is_widht && print->is_minus == 0)
		{
			print->is_widht--;
			print->is_len += print->is_widht;
			while (print->is_widht > 0)
			{
				write(1, " ", 1);
				print->is_widht--;
			}
		}
		write(1, "\0", 1);
		print->is_len++;
		return (0);
	}
	else
		return (1);
}

static int	ft_ch(char c, t_print *print)
{
	if (c == '\0')
	{
		if (print->is_minus)
		{
			write(1, "\0", 1);
			print->is_len += print->is_minus;
			print->is_minus--;
			while (print->is_minus > 0)
			{
				write(1, " ", 1);
				print->is_minus--;
			}
		}
		return (0);
	}
	else
		return (1);
}

char	*print_char(char c, t_print *print)
{
	char	*str;

	if (checkker(c, print) == 0 || ft_ch(c, print) == 0)
		return (NULL);
	str = ft_strnew(1, print);
	str[0] = c;
	return (str);
}
