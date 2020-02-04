/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d_utils.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/15 14:53:31 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 16:17:20 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_isalpha(int c)
{
	if (c == 'W' || c == 'N' || c == 'E' || c == 'S')
		return (1);
	else
		return (0);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	if ((s2 = malloc(sizeof(char) * len + 1)) == 0)
		return (0);
	s2[len] = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

int tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

double	whose_higher(r_list raycasting)
{
	if (raycasting.long_horizontal < raycasting.long_vertical
			&& raycasting.long_horizontal > 0)
		return (raycasting.long_horizontal);
	else if (raycasting.long_vertical > 0)
		return (raycasting.long_vertical);
	printf("Bad values.\nVertical : %f\nHorizontal : %f\n", raycasting.long_vertical, raycasting.long_horizontal);
	exit(1);
}
