/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 11:11:18 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 16:09:30 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_cpy_join(char const *s1, char const *s2, char *result)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = 0;
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		len;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i])
		i++;
	len = i;
	i = 0;
	while (s2[i])
		i++;
	len += i;
	result = malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	ft_cpy_join(s1, s2, result);
	return (result);
}
