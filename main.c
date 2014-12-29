/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:27:52 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/29 21:04:30 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int main()
{
	ft_printf("retour ft = %d\n", ft_printf("\nje suis, %ld %c %sjkfdsj %x\n", 15545454552, 'c', "blabla", -256));
	printf("retour printf = %d", printf("%ld\n", 6354543524516));
	return (0);
}
