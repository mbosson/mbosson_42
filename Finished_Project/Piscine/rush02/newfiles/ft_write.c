/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_write.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/17 21:06:36 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/18 11:38:55 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header.h"

int		ft_write(int number)
{
	int t;
	int i;

	i = 0;
	if (number == 0)
	{
		arthur('0');
		return (0);
	}
	else
	{
		t = ft_find_closest(number);
		arthur(number / t);
		arthur(t);
		return (number = number % t);
	}
}
