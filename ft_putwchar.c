/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:56:02 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/22 11:03:29 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <wchar.h>
#include <locale.h>

void			ft_putwchar(unsigned int *k)
{
	int			index;

	index = 0;
	while (k[index] > 0)
		write(1, &(k[index++]), 1);
}
