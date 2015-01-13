/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:29:44 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/13 14:21:34 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <wchar.h>
#include "libftprintf.h"

void	ft_putwstr(wchar_t *s)
{
	while (*s != '\0')
	{
		ft_putwchar(*s, 4);
		s++;
	}
}
