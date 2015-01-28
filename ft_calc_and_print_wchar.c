/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_and_print_wcha.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 15:12:48 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/22 15:43:59 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <limits.h>
#include <stdlib.h>

static int			ft_calc_and_print_wchar_suite(unsigned int wc, char *tmp)
{
	int				ret;
	unsigned int	*k;

	ret = 0;
	tmp = ft_strnew(13);
	tmp = ft_dectobin(wc);
	tmp = ft_unimask(tmp, ft_strlen(tmp));
	k = ft_split_int_etoile(tmp);
	while (k[ret] > 0)
	{
		k[ret] = ft_bintodec(k[ret]);
		ret++;
	}
	ft_putwchar(k);
	return (ret);
}

int					ft_calc_and_print_wchar(wchar_t wc, char *tmp)
{
	unsigned int	ui;

	ui = (unsigned int)wc;
	if (ui <= UCHAR_MAX)
	{
		ft_putchar((unsigned char)ui);
		return (1);
	}
	else
		return (ft_calc_and_print_wchar_suite(ui, tmp));
}
