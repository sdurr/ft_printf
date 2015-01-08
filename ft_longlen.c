/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: getrembl <getrembl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 12:17:27 by getrembl          #+#    #+#             */
/*   Updated: 2015/01/08 12:50:10 by getrembl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long		ft_longlen(long l)
{
	long	ret;

	ret = 1;
	if (l < 0)
	{
		ret++;
		l *= -1;
	}
	while ((l /= 10) > 0)
		ret++;
	return (ret);
}
