/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:27:52 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/29 22:42:56 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int main()
{
	ft_printf("retour ft = %d\n", ft_printf("\nje suis,%b \n", -153));
	printf("retour printf = %d", printf("%x %x \n", 11, -11));
	return (0);
}
