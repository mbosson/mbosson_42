/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 11:21:59 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 17:53:11 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s_ret;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			return (s_ret = (char *)s + i);
		i++;
	}
	if (c == 0)
		return (s_ret = (char *)s + i);
	return (0);
}
