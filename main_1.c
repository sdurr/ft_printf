/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 16:16:25 by getrembl          #+#    #+#             */
/*   Updated: 2015/01/09 12:17:57 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int		main(void)
{
	unsigned long long l;

	l = ULLONG_MAX;
	ft_printf("%jd\n", l);
	printf("%jd\n", l);
	return (0);
}
