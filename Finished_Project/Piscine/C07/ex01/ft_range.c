/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_range.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/14 15:38:11 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/15 18:05:30 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *tab;
	int i;
	
	tab = malloc((max - min) * sizeof(int));
	i = 0;
	if (min >= max)
	{
		tab = NULL;
		return(tab);
	}
	while (i < max - min)
	{
		tab[i] = min;
		i++;
		min++;
	}
	return (tab);
}

int		main(void)
{
	int i;

	i = 0;
	while (i < 7)
	{
		printf("%d\n", *ft_range(5, 10) + i);
		i++;
	}
	return (0);
}
