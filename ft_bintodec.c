/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bintodec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:56:42 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/19 14:57:52 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned int		ft_bintodec(unsigned int n)
{
	int dec;
	int i;
	int rem;

	dec = 0;
	i = 0;
	while (n != 0)
	{
		rem = n % 10;
		n /= 10;
		dec += rem * ft_recursive_power(2,i);
		++i;
	}
	return (dec);
}
