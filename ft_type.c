/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:24:57 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/03 11:21:12 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

static int			ft_type_d(char *s, int i, va_list ap, char **aff)
{
	int j;

	j = i;
	while (s[j] != '%')
		j--;
	if ((s[j + 1] == '+' && s[i] == 'd') || (s[j + 1] == '+' && s[i] == 'i')
		|| (s[j + 2] == '+' && s[i] == 'd'))
		return (ft_print_d_plus(ap, s, i, aff));
	if ((s[i] == 'd' && s[i - 1] == 'h')
		|| (s[i] == 'i' && s[i - 1] == 'h'))
		return (ft_print_d_h(ap, s, i, aff));
	if (s[i - 1] == 'l' && s[i] == 'd' && s[j + 2] == 'l')
		return (ft_print_d_long_long(ap, s, i, aff));
	if ((s[i] == 'D') || (s[i] == 'd' && s[j + 1] == 'l')
		|| (s[i] == 'i' && s[j + 1] == 'l')
		|| (s[i] == 'd' && s[j + 1] == 'j') || (s[i] == 'i' && s[i - 1] == 'j'))
		return (ft_print_d_maj(ap, s, i, aff));
	if (s[i] == 'd' || s[i] == 'i')
		return (ft_print_d(ap, s, i, aff));
	return (-1);
}

static int			ft_type_x(char *s, int i, va_list ap, char **aff)
{
	int j;

	j = i;
	while (s[j] != '%')
		j--;
	if ((s[i] == 'x' && s[j + 1] == 'l') || (s[i] == 'x' && s[j + 1] == 'j'))
		return (ft_print_x_long(ap, s, i, aff));
	if ((s[i] == 'X' && s[j + 1] == 'l') || (s[i] == 'X' && s[j + 1] == 'j'))
		return (ft_print_x_maj_long(ap, s, i, aff));
	if (s[i] == 'x' && s[j + 1] == 'h')
		return (ft_print_x_h(ap, s, i, aff));
	if (s[i] == 'X' && s[j + 1] == 'h')
		return (ft_print_x_maj_h(ap, s, i, aff));
	if (s[i] == 'x')
		return (ft_print_x(ap, s, i, aff));
	if (s[i] == 'X')
		return (ft_print_x_maj(ap, s, i, aff));
	if (s[i] == '%')
		return (ft_print_modulo(s, i, aff));
	return (-1);
}

static int			ft_type_z(char *s, int i, va_list ap, char **aff)
{
	if (s[i - 1] == 'z' && s[i] == 'u')
		return (ft_print_u_size_t(ap, s, i, aff));
	if (s[i - 1] == 'z' && s[i] == 'o')
		return (ft_print_o_size_t(ap, s, i, aff));
	if (s[i - 1] == 'z' && s[i] == 'x')
		return (ft_print_x_size_t(ap, s, i, aff));
	if (s[i - 1] == 'z' && s[i] == 'X')
		return (ft_print_x_maj_size_t(ap, s, i, aff));
	if ((s[i - 1] == 'z' && s[i] == 'd') || (s[i - 1] == 'z' && s[i] == 'i'))
		return (ft_print_d_size_t(ap, s, i, aff));
	if (s[i] == 'C' || (s[i] == 'c' && s[i - 1] == 'l'))
		return (ft_print_c_maj(ap, s, i, aff));
	if (s[i] == 'c')
		return (ft_print_c(ap, s, i, aff));
	if (s[i] == 'b')
		return (ft_print_b(ap, s, i, aff));
	if (s[i] == 'p')
		return (ft_print_p(ap, s, i, aff));
	return (-1);
}

static int			ft_type_s_u_o(char *s, int i, va_list ap, char **aff)
{
	int		j;

	j = i;
	while (s[j] != '%')
		j--;
	if (s[i] == 'S' || (s[i] == 's' && s[i - 1] == 'l'))
		return (ft_print_s_maj(va_arg(ap, wchar_t *), s, i, ft_strnew(13)));
	if (s[i] == 's')
		return (ft_print_s(va_arg(ap, char *), s, i, aff));
	if (s[i] == 'U' || (s[i] == 'u' && s[j + 1] == 'l')
		|| (s[i] == 'u' && s[j + 1] == 'j'))
		return (ft_print_u_maj(ap, s, i, aff));
	if (s[i] == 'u' && s[j + 1] == 'h')
		return (ft_print_u_h(ap, s, i, aff));
	if (s[i] == 'u')
		return (ft_print_u(ap, s, i, aff));
	if (s[i] == 'O' || (s[i] == 'o' && s[j + 1] == 'l')
		|| (s[i] == 'o' && s[j + 1] == 'j'))
		return (ft_print_o_maj(ap, s, i, aff));
	if (s[i] == 'o' && s[j + 1] == 'h')
		return (ft_print_o_h(ap, s, i, aff));
	if (s[i] == 'o')
		return (ft_print_o(ap, s, i, aff));
	return (-1);
}

int					ft_type(char *s, int i, va_list ap, char **aff)
{
	int		j;
	char	*tmp;

	tmp = ft_strnew(2);
	tmp[0] = s[i];
	j = i;
	while (s[j] != '%')
		j--;
	if ((s[i - 1] == 'z' && s[i] != 'O' && s[i] != 'U' && s[i] != 'D')
		|| s[i] == 'c' || s[i] == 'C' || s[i] == 'p' || s[i] == 'b')
		return (ft_type_z(s, i, ap, aff));
	if (s[i] == 'd' || s[i] == 'i' || s[i] == 'D')
		return (ft_type_d(s, i, ap, aff));
	if (s[i] == 'x' || s[i] == 'X' || s[i] == '%')
		return (ft_type_x(s, i, ap, aff));
	if (s[i] == 's' || s[i] == 'S' || s[i] == 'u' || s[i] == 'o'
		|| s[i] == 'U' || s[i] == 'O')
		return (ft_type_s_u_o(s, i, ap, aff));
	if (s[i] == '\0')
		return (0);
	if ((s[i - 1] >= '0' && s[i - 1] <= '9')
		|| (s[i - 2] >= '0' && s[i - 2] <= '9'))
		if (s[j + 1] == '-')
			*aff = ft_strjoin(*aff, tmp);
	return (ft_space_number(s, i, aff));
}
