/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 10:10:48 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/18 12:00:17 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int			i;
	const char				*str_src;
	char					str_src_cpy[n];
	char					*str_dest;

	str_src = src;
	str_dest = dest;
	if (!str_dest && !str_src && n)
		return (0);
	i = 0;
	while (i < n)
	{
		str_src_cpy[i] = str_src[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		str_dest[i] = str_src_cpy[i];
		i++;
	}
	return (str_dest);
}
