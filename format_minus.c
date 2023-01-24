/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_minus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medric <medric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:26:07 by medric            #+#    #+#             */
/*   Updated: 2021/12/10 18:26:07 by medric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_malloc(t_print *print, char *str)
{
	if (!str)
	{
		str = NULL;
		print->error = -1;
	}
	return (print->error);
}

static char	*ft_subjoin4(char *s1, char *s2, t_print *print)
{
	int		s1l;
	size_t	s2l;
	char	*new;
	int		r;

	r = 0;
	s1l = print->value_len;
	s2l = ft_strlen(s2);
	new = (char *)malloc((s1l + s2l + 1) * sizeof(char));
	if (ft_check_malloc(print, new) == -1)
		return (NULL);
	while (r < print->value_len)
	{
		new[r] = *s1++;
		r++;
	}
	while (*s2)
	{
		new[r] = *s2++;
		r++;
	}
	new[r++] = '\0';
	return (new);
}

char	*ft_format_minus(t_print *print, int c, int *p)
{
	char	*str;
	char	*new;
	int		s_len;

	new = NULL;
	s_len = *p - (print->value_len);
	str = ft_strnew(s_len, print);
	str = ft_memset(str, c, s_len);
	new = ft_subjoin4(print->specifier_value, str, print);
	free(print->specifier_value);
	free(str);
	return (new);
}

void	format_minus(t_print *print)
{
	if (print->is_minus > print->value_len)
	{
		print->specifier_value = ft_format_minus(print, ' ', &print->is_minus);
		print->value_len = print->is_minus;
	}
	return ;
}
