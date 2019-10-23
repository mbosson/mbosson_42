/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 16:44:37 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 15:26:16 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, unsigned long n)
{
	unsigned char				*str;
	unsigned int				i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n && str[i] != 0)
	{
		str[i] = 0;
		i++;
	}
}
