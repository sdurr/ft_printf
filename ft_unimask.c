/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unimask.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 15:05:23 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/24 11:54:15 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*ft_wcinmask(char *mask, char *wc)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = ft_strdup(mask);
	i = ft_strlen(mask);
	j = ft_strlen(wc);
	while (j >= 0)
	{
		if (tmp[i] == 'x')
			tmp[i] = wc[j--];
		if (tmp[i] != 'x')
			i--;
	}
	i = ft_strlen(tmp) + 1;
	while (i-- >= 0)
		if (tmp[i] == 'x')
			tmp[i] = '0';
	return (tmp);
}

char			*ft_unimask(char *bin, size_t digit)
{
	char	*mask_2;
	char	*mask_3;
	char	*mask_4;

	mask_2 = ft_strdup("110xxxxx10xxxxxxx");
	mask_3 = ft_strdup("1110xxxx10xxxxxx10xxxxxxx");
	mask_4 = ft_strdup("11110xxx10xxxxxx10xxxxxx10xxxxxxx");
	if (digit >= 8 && digit <= 11)
		bin = ft_wcinmask(mask_2, bin);
	if (digit >= 12 && digit <= 16)
		bin = ft_wcinmask(mask_3, bin);
	if (digit >= 17 && digit <= 21)
		bin = ft_wcinmask(mask_4, bin);
	return (bin);
}
