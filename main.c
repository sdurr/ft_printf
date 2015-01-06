/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:27:52 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/06 12:04:59 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
#include <string.h>
#include <unistd.h>

int main()
{
	unsigned long int j;

	j = 42;
	//ft_printf("retour ft = %d\n", ft_printf("s: %s, p: %p, d:%d\n", "a string", &strlen, 42));
	printf("retour ft = %d\n", printf("%U", j));
	return (0);
}
