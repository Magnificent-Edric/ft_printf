/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:19:50 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:19:50 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_substr(char *s, unsigned int start, size_t len, t_print *print)
{
	int				r;
	size_t			i;
	char			*widht;

	r = 0;
	i = 0;
	widht = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ft_check_malloc(print, widht) == -1)
		return (-1);
	while (i < len)
	{
		widht[i] = s[i + start];
		i++;
	}
	widht[i++] = '\0';
	ft_atoi(widht, &r);
	free(widht);
	return (r);
}
