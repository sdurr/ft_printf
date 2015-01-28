/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:22:54 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/22 18:52:05 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdarg.h>

int	ft_print_modulo(char *s, int i, char **aff)
{
	char	*tmp;
	size_t	j;

	tmp = ft_strnew(13);
	j = i;
	i--;
	while (s[i] >= '0' && s[i] <= '9')
		tmp[j++] = s[i--];
	ft_number_befor_char(" ", s, j, aff);
	j = 0;
	tmp = ft_strdup("%");
	*aff = ft_strjoin(*aff, tmp);
	return (0);
}
