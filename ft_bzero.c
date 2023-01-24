/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:25:37 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:25:37 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_bzero(void *dest, size_t len)
{
	size_t			i;
	unsigned char	*new_dest;

	i = 0;
	new_dest = dest;
	while (i < len)
	{
		*new_dest = 0;
		new_dest++;
		i++;
	}
	return (dest);
}
