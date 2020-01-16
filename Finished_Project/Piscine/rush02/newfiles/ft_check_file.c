/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_file.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/18 11:43:49 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/18 11:44:01 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header.h"

int		ft_dict_error(void)
{
	write(1, "Dict Error\n", 11);
	return (0);
}

int		ft_check_file(char *giant, int i)
{
	while (giant[i])
	{
		if (giant[i] != '\n')
		{
			if (giant[i] < '0' || giant[i] > '9')
				return (ft_dict_error());
			while (giant[i] >= '0' && giant[i] <= '9' && giant[i] != '\0')
				i++;
			while (giant[i] == ' ' && giant[i] != '\0')
				i++;
			if (giant[i] != ':')
				return (ft_dict_error());
			i++;
			while (giant[i] == ' ' && giant[i] != '\0')
				i++;
			if (giant[i] < 32)
				return (ft_dict_error());
			while (giant[i] >= 32 && giant[i] != '\0')
				i++;
			if (giant[i] != '\n')
				return (ft_dict_error());
		}
		i++;
	}
	return (1);
}
