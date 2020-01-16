/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   find_closest.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/18 08:22:11 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/18 11:46:26 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header.h"

int		ft_find_closest(int number_given, char *tab_struct)
{
	int t;
	int i;

	i = 0;
	t = 0;
	while (tab_struct[i].number_int != -1)
	{
		if (tab_struct[i].number_int > t
				&& tab_struct[i].number_int <= number_given)
			t = tab_struct[i].number_int;
		i++;
	}
	return (t);
}
