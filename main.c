/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:27:52 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/29 19:16:40 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int main()
{
	ft_printf("retour ft = %d\n", ft_printf("\nje suis, %+d %c %sjkfdsj %#x\n", 12, 'c', "blabla", 256));
	printf("retour printf = %d", printf("\nje suis, %+d %c %s %#x\n", 12, 'c', "blabla", 256));
	return (0);
}
