/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:24:57 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/09 10:52:27 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdarg.h>

int	ft_type(char *s, int i, va_list ap, char **aff)
{
	int j;

	j = i;
	while (s[j] != '%')
		j--;
	if ((s[i - 1] == '+' && s[i] == 'd') || (s[i - 1] == '+' && s[i] == 'i'))
	{
		return (ft_print_d_plus(ap, aff));
	}
	if (s[i -1] == 'l' && s[i] == 'd' && s[j + 2] == 'l')
		return (ft_print_d_long_long(ap, s, i, aff));
	if (s[i - 1] == 'z' && s[i] == 'x')
		return(ft_print_x_size_t(ap, s, i, aff));
		if (s[i - 1] == 'z' && s[i] == 'X')
		return(ft_print_x_maj_size_t(ap, s, i, aff));
		if ((s[i - 1] == 'z'  && s[i] == 'd') || (s[i - 1] == 'z'  && s[i] == 'i'))
		return(ft_print_d_size_t(ap, s, i, aff));
	if ((s[i] == 'D') || (s[i] == 'd' && s[j + 1] == 'l') || (s[i] == 'i' && s[j + 1] == 'l') || (s[i] == 'd' && s[j + 1] == 'j') || (s[i] == 'i' && s[i - 1] == 'j'))
		return (ft_print_d_maj(ap, s, i, aff));
	if (s[i] == 'd' || s[i] == 'i' || (s[j + 1] == 'h' && s[i] == 'd'))
		return (ft_print_d(ap, s, i, aff));
	if (s[i] == 'U' || (s[i] == 'u' && s[j + 1] == 'l') || (s[i] == 'u' && s[j + 1] == 'j'))
		return (ft_print_u_maj(ap, s, i, aff));
	if (s[i] == 'u')
		return (ft_print_u(ap, s, i, aff));
	if (s[i] == 'O' || (s[i] == 'o' && s[j + 1] == 'l') || (s[i] == 'o' && s[j + 1] == 'j'))
		return (ft_print_o_maj(ap, s, i, aff));
	if (s[i] == 'o')
		return (ft_print_o(ap, s, i, aff));
	if (s[i] == 'S')
		return (ft_print_s_maj(ap, s, i));
	if (s[i] == 's')
		return (ft_print_s(ap, s, i, aff));
	if (s[i] == 'b')
		return (ft_print_b(ap, s, i, aff));
	if (s[i] == 'p')
		return (ft_print_p(ap, s, i, aff));
	if (s[i] == 'c')
		return (ft_print_c(ap, s, i, aff));
	if (s[i] == 'C')
		return (ft_print_c_maj(ap, s, i));
	if (s[i] == '%')
	{
		*aff = ft_strjoin(*aff, "%");
		return (0);
	}
	if ((s[i] == 'x' && s[j + 1] == 'l') || (s[i] == 'x' && s[j + 1] == 'j'))
		return (ft_print_x_long(ap, s, i, aff));
	if ((s[i] == 'X' && s[j + 1] == 'l') || (s[i] == 'x' && s[j + 1] == 'j'))
		return (ft_print_x_maj_long(ap, s, i, aff));
	if (s[i] == 'x')
		return (ft_print_x(ap, s, i, aff));
	if (s[i] == 'X')
		return (ft_print_x_maj(ap, s, i, aff));
	if (s[i] == '\0')
		return (0);
	return (-1);
}
