/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/17 12:29:17 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/17 13:17:51 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <header.h>

int print_number(char *dict, int number, int counter)
{
	int count;

	count = 1;
	if (number >= 10)
	{
		count++;
		ft_read(dict, number % 10, count);
		print_number(dict, number / 10, count);
	}
	if (number <= 9)
	{
		count++;
		ft_read(dict, number, count);
	}

}


