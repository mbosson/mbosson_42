/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_range.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/14 15:38:11 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/14 19:39:52 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int        ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int *tab;

	i = 0;
	tab  = malloc((max - min) * sizeof(int));
	if (tab == 0)
		return(-1);
	if (min >= max)
		return(0);
	else
	{
		while (min < max)
		{
			tab[i] = min;
			i++;
			min++;
		}
	}
	*range = tab;
	return (i + 1);
}
