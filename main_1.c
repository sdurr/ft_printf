/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 16:16:25 by getrembl          #+#    #+#             */
/*   Updated: 2015/01/09 13:21:19 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int		main(void)
{
	unsigned long long l;

	l = SHRT_MAX;
	printf("%d", ft_printf("%hhu %hhu\n", l +4200, l));
	printf ("%d", printf("%hhu %hhu\n", l + 4200, l));
	return (0);
}
