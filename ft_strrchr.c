/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 12:57:07 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 09:14:28 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s_ret;

	i = 0;
	s_ret = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			s_ret = (char *)s + i;
		i++;
	}
	if (c == 0)
		s_ret = (char *)s + i;
	return (s_ret);
}
