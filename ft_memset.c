/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:23:59 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:23:59 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *s, int c, int len)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (len > 0)
	{
		*str = (unsigned char)c;
		str++;
		len--;
	}
	return (s);
}
