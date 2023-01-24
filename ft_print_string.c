/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:22:29 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:22:29 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_string(char *str, t_print *print)
{
	int		res;
	char	*new;
	int		i;

	res = 0;
	i = 0;
	res = ft_strlen(str);
	new = ft_strnew(res, print);
	if (print->space && res != 0)
		new[i] = ' ';
	while (res > i)
	{
		new[i] = str[i];
		i++;
	}
	return (new);
}
