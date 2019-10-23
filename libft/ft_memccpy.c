/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 10:01:27 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 16:16:22 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int			i;
	const unsigned char		*strsrc;
	unsigned char			*strdest;
	unsigned char			c2;

	c2 = c;
	strsrc = src;
	strdest = dest;
	i = 0;
	while (i < n)
	{
		strdest[i] = strsrc[i];
		if (strdest[i] == c2)
		{
			strdest[i] = strsrc[i];
			return (strdest + i + 1);
		}
		i++;
	}
	return (0);
}
