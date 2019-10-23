/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 14:13:06 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 16:44:35 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_free_all(char **giant)
{
	int		i;

	i = 0;
	while (giant[i])
	{
		free(giant[i]);
		i++;
	}
	free(giant);
	return (0);
}

static	char	**ft_malloc_tab(char const *s, char c)
{
	int		i;
	int		len_tab;
	char	**giant;

	i = 0;
	len_tab = 0;
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != 0)
			len_tab++;
		while (s[i] != c && s[i] != 0)
			i++;
	}
	giant = ft_calloc(sizeof(char*) * (len_tab + 1), 1);
	if (giant == 0)
		return (0);
	giant[len_tab] = 0;
	return (giant);
}

static	int		ft_cpy(char **giant, char const *str, int *start_end, int j)
{
	int		i;

	i = 0;
	giant[j] = (char *)malloc(sizeof(char) * (start_end[1] - start_end[0] + 1));
	if (giant[j] == 0)
		return (ft_free_all(giant));
	while (i < start_end[1] - start_end[0])
	{
		giant[j][i] = str[start_end[0] + i];
		i++;
	}
	giant[j][i] = 0;
	return (1);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		start_end[2];
	char	**giant;

	if (s == 0)
		return (0);
	if (!(giant = ft_malloc_tab(s, c)))
		return (0);
	i = 0;
	j = -1;
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		start_end[0] = i;
		while (s[i] != c && s[i] != 0)
			i++;
		start_end[1] = i;
		j++;
		if (s[i] != 0 || s[i - 1] != c)
			if (ft_cpy(giant, s, start_end, j) == 0)
				return (0);
	}
	return (giant);
}
