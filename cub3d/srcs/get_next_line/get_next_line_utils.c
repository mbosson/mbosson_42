/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/12 11:04:09 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 16:13:26 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int				free_all(char *staticstr, char *str, int nb)
{
	if (nb >= 1)
	{
		free(staticstr);
		staticstr = 0;
	}
	if (nb != 1)
		free(str);
	return (-1);
}

static	char	*ft_cpy_join(char const *s1, char const *s2, char *result)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j] != 0 && s2[j] != 0)
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = 0;
//	free((char *)s1);
	return (result);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		len;

	if (!s1 || !s2)
		return (0);
	len = 0;
	i = 0;
	while (s1[len])
		len++;
	while (s2[i])
		i++;
	len += i;
	if ((result = malloc(sizeof(char) * (len + 1))) == 0)
	{
		free((char *)s1);
		free((char *)s2);
		return (0);
	}
	return (ft_cpy_join(s1, s2, result));
}
