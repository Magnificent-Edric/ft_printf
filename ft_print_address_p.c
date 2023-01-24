/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address_p.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:22:48 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:22:48 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	lenght(unsigned long int n)
{
	size_t	len;

	len = 1;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int	ft_convert_hex(unsigned long int nb, char *str)
{
	char	*r;
	int		i;

	i = 0;
	r = str;
	while (nb > 0)
	{
		r[i++] = "0123456789abcdef"[nb % 16];
		nb /= 16;
	}
	r[i++] = 'x';
	r[i++] = '0';
	return (i);
}

static char	*ft_address(unsigned long int new, t_print *print)
{
	char	*str;
	int		tmp;
	int		xec;
	int		r;
	int		i;

	r = lenght(new);
	str = (char *)malloc(sizeof(char) * (r + 3));
	if (ft_check_malloc(print, str) == -1)
		return (NULL);
	xec = ft_convert_hex(new, str);
	i = xec;
	r = 0;
	while (r < xec - 1)
	{
		tmp = str[xec - 1];
		str[xec - 1] = str[r];
		str[r] = tmp;
		xec--;
		r++;
	}
	str[i] = '\0';
	return (str);
}

char	*printad(unsigned long int new, t_print *print)
{
	char	*str;

	if (new == 0)
		return (NULL);
	str = ft_address(new, print);
	return (str);
}
