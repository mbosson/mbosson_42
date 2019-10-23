/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 12:40:50 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 15:44:24 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static	char		*ft_empty(void)
{
	char					*ptr;

	ptr = malloc(sizeof(char) * 1);
	ptr[0] = 0;
	return (ptr);
}

static	int			ft_test(char const *s1, char const *set, int i)
{
	int						j;

	j = 0;
	while (set[j] != 0)
	{
		if (s1[i] == set[j])
			return (1);
		j++;
	}
	return (0);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	size_t					i;
	size_t					start;
	unsigned int			end;
	char					*str;

	if (s1 == 0)
		return (0);
	i = 0;
	while (ft_test(s1, set, i) == 1)
		i++;
	start = i;
	i = ft_strlen(s1);
	if (start == i)
		return (ft_empty());
	while (ft_test(s1, set, i - 1) == 1)
		i--;
	end = i;
	if ((str = (char *)malloc(sizeof(char) * (end - start + 1))) == 0)
		return (0);
	i = -1;
	while (++i + start < end)
		str[i] = s1[start + i];
	str[i] = 0;
	return (str);
}
