/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 10:07:56 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 15:24:16 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*strcpy;

	i = 0;
	while (s1[i])
		i++;
	if ((strcpy = malloc((i + 1) * sizeof(char))) == 0)
		return (0);
	j = 0;
	while (j <= i)
	{
		strcpy[j] = s1[j];
		j++;
	}
	return (strcpy);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*join;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	if (!(join = malloc(i + j + 1)))
		return (0);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
    {
        join[i + j] = s2[j];
        j++;
    }
	join[i + j] = 0;
	return (join);
}

int     usefull_free(char **str1, int val_ret)
{
    free(*str1);
    *str1 = 0;
    return (val_ret);
}
