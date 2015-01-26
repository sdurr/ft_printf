/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:43:55 by sdurr             #+#    #+#             */
/*   Updated: 2015/01/24 11:55:04 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>
#include <string.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		c;
	char	*ret;
	int		i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	c = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(ret = (char *)malloc(sizeof(char*) * c)))
		return (NULL);
	while (*s1 != '\0')
	{
		ret[i++] = *s1;
		s1++;
	}
	while (*s2 != '\0')
	{
		ret[i++] = *s2;
		s2++;
	}
	ret[i] = '\0';
	return (ret);
}
