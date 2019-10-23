/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 14:51:12 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 14:51:13 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char				*str_s1;
	const char				*str_s2;
	unsigned int			i;

	str_s1 = s1;
	str_s2 = s2;
	i = 0;
	while (i < n)
	{
		if (str_s1[i] != str_s2[i])
			return ((unsigned char)str_s1[i] - (unsigned char)str_s2[i]);
		i++;
	}
	return (0);
}
