/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:11:09 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/03 09:16:35 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char		*ft_strnew(size_t size)
{
	char	*ret;
	int		i;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (size)
	{
		ret[i] = '\0';
		size--;
		i++;
	}
	return (ret);
}
