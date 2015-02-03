/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:11:09 by sdurr             #+#    #+#             */
/*   Updated: 2015/02/03 09:21:17 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char		*ft_strnew(size_t size)
{
	char	*str;

	if(!(str = malloc (sizeof(char) * size)))
		return (NULL);
	while (size--)
		*str++ = '\0';
	return (str);
}
