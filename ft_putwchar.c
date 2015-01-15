/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:56:02 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/14 17:39:09 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <wchar.h>

void				ft_putwchar(wchar_t c, size_t nbyte)
{
//	unsigned int	i;

//	i = 0;
//	while (i < nbyte)
//	{
		write(1, &(c), nbyte);
//		i++;
//	}
}
