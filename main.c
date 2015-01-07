/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:27:52 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/07 17:33:06 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
#include <string.h>
#include <unistd.h>

static void test_simple_mix(char c)
{
	write(1, &c, 1);
}
int main()
{
	printf("retour ft = %d\n", ft_printf("s: %s, p: %p, d:%d", "a string", &test_simple_mix, 42));
		   printf("retour print = %d\n", printf("s: %s, p: %p, d:%d", "a string", &test_simple_mix, 42));
	return (0);
}
