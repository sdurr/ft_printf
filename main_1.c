/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 16:16:25 by getrembl          #+#    #+#             */
/*   Updated: 2015/01/08 18:31:09 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int		main(void)
{
	unsigned long l;

	l = ULONG_MAX;
	printf("modulo lx ULONG_MAX = %lx \nmodulo lo 0 = %lo\n", l, 0L);
	return (0);
}
