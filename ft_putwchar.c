/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:56:02 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/20 12:31:00 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <wchar.h>
#include <locale.h>

void				ft_putwchar(unsigned int *c, int nbprint)
{
	int	i;

	i = 0;
	while (i <= nbprint)
	{
		write(1, &(c[i]), 1);
		i++;
	}
}
