/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 15:27:52 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/07 11:08:36 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
#include <string.h>
#include <unistd.h>

int main()
{

	printf("retour ft = %d\n", ft_printf("%.u, %.0u", 0, 0));
	printf("retour print = %d\n", printf("%.u, %.0u", 0, 0));
	return (0);
}
