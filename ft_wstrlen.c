/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:39:39 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/21 12:19:17 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <wchar.h>
#include "libft.h"

size_t		ft_wstrlen(wchar_t *s)
{
	size_t cpt;

	cpt = 0;
	if (!s || !s[cpt])
		return (-1);
	while (s[cpt] != '\0')
		cpt++;
	return (cpt);
}
