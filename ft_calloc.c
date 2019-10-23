/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_calloc.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 10:16:51 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 16:22:26 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void				*ptr;
	size_t				i;

	i = 0;
	ptr = malloc(count * size);
	if (ptr == 0)
		return (0);
	while (i < size * count)
	{
		((unsigned char*)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
