/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:24:47 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:24:47 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_subjz(char *s1, char *s2, unsigned int s2_start, t_print *print)
{
	size_t	s1l;
	size_t	s2l;
	char	*new;

	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2) - s2_start;
	new = (char *)malloc((s1l + s2l + 1) * sizeof(char));
	if (ft_check_malloc(print, new) == -1)
		return (NULL);
	s1 += s2_start;
	if (*s1 == '-' && *s2 == '0')
	{
		*new++ = '-';
		s1++;
	}
	while (*s2)
		*new++ = *s2++;
	while (*s1)
		*new++ = *s1++;
	*new = '\0';
	return (new - (s1l + s2l));
}

char	*ft_format(t_print *print, int c, int *p)
{
	char	*str;
	char	*new;
	int		s_len;

	s_len = *p - (print->value_len);
	str = ft_strnew(s_len, print);
	str = ft_memset(str, c, s_len);
	if (print->is_zero)
		new = ft_subjz(print->specifier_value, str, 0, print);
	else
	{
		new = ft_subjoin(print->specifier_value, str, 0, print);
	}
	free(print->specifier_value);
	free(str);
	return (new);
}
