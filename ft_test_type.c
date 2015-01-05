/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 14:14:27 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/05 15:41:22 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdarg.h>

int		ft_test_type(char *s)
{
	int i;

	i = 0;
	while (s[i++])
		while (s[i] != '%' && s[i])
		{
			if (s[i] == '#' && s[i - 1] == '%')
				i++;
			else if (s[i] == 'x' && s[i - 1] == '#')
				i++;
			else if (s[i] == '+' && s[i + 1] == 'd')
				i++;
			else if (s[i] == '+' && s[i + 1] == 'i')
				i++;
			else if (s[i] == '+')
			{
				ft_putstr_fd("error : '+' flags used with %", 2);
				ft_putchar_fd(s[i + 1], 2);
				ft_putchar_fd('\n', 2);
				return (-1);
			}
			i++;
		}
	return (1);
}
