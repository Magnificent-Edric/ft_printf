/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:20:08 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:20:08 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnew(size_t size, t_print *print)
{
	size_t	i;
	char	*new;

	i = 0;
	if ((print->specifier == 's' || print->specifier == 'd'
			|| print->specifier == 'i') && print->space)
		size++;
	new = (char *)malloc((size + 1) * sizeof(char));
	if (ft_check_malloc(print, new) == -1)
		return (NULL);
	else
	{
		while (i < size)
		{
			new[i] = '\0';
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
