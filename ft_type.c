/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:24:57 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/27 16:22:09 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdarg.h>

int	ft_type(char *s, int i, va_list ap)
{
  if (s[i] == 'd')
	  return (ft_print_d(ap));
  if (s[i] == 's')
    return (ft_print_s(ap));
  if (s[i] == 'c')
    return (ft_print_c(ap));
  if (s[i] == '%')
    {
      ft_putchar ('%');
      return (1);
    }
  return (0);
}
