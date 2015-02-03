/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:43:55 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/03 09:27:53 by getrembl         ###   ########.fr       */
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
	c = 0;
	while (s1[c] != '\0')
		ret[i++] = s1[c++];
	c = 0;
	while (s2[c] != '\0')
		ret[i++] = s2[c++];
	ret[i] = '\0';
	s1 = ft_strnew(15);
	s2 = ft_strnew(15);
	return (ret);
}
