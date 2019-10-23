/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_substr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 10:34:16 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 15:27:11 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s1, unsigned int start, size_t len)
{
	char				*s2;
	size_t				i;
	size_t				j;

	i = 0;
	j = 0;
	if (s1 == 0)
		return (0);
	if (start > len)
	{
		s2 = malloc(sizeof(char) * 1);
		s2[0] = 0;
		return (s2);
	}
	if ((s2 = malloc(sizeof(char) * (len + 1))) == 0)
		return (0);
	i = start;
	while (j < len)
	{
		s2[j] = s1[i];
		i++;
		j++;
	}
	s2[j] = 0;
	return (s2);
}
