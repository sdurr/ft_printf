/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_maj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:23:12 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/22 09:09:34 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <wchar.h>
#include "libftprintf.h"
#include <stdlib.h>

int					ft_print_c_maj(va_list ap, char *s, int i, char **aff)
{
	unsigned int	wc;
	char *tmp;
	int j;
	int test;

	wc = va_arg(ap, unsigned int);
	j = 0;
	tmp = ft_strnew(13);
	test = ft_space_number(s, i, aff);
	if ((wc == 0 && j == 0 && s[i] != ' ' && s[i + 1] != '0' && test == 0)
		|| (wc == 0 && s[i] == '.' && j == 0 && test == 0) || (wc == 0 && s[i] == '+'))
		return (1);
	if (s[i] == ' ' && wc == 0)
		*aff = ft_strjoin (*aff, " ");
	return (ft_calc_and_print_wchar(wc, tmp));
}
