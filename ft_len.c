/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:24:07 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:24:07 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len(long int n)
{
	size_t	len;

	len = 1;
	if (n < 0)
	{
		len = 2;
		n = n * (-1);
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}