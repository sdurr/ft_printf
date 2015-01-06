/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_maj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 18:43:32 by getrembl          #+#    #+#             */
/*   Updated: 2015/01/06 19:32:45 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "libftprintf.h"

int				ft_print_d_maj(va_list ap)
{
	long		l;
	char		*longint;

	l = va_arg(ap, long);
	longint = ft_litoa(l);
	ft_putnbr_long(l);
	return (ft_strlen(longint));
}

// void ft_putnbr_long(long n);     effectue affichage d'un long int
// char *ft_litoa(long n);          tranforme un long int en char*
// size_t ft_strlen(char *s);       compte le nombre de char d'un char*
