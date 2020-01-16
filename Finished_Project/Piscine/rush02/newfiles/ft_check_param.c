/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_param.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/17 21:08:41 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/18 11:41:00 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header.h"

int		ft_strlen(char *file)
{
	int i;

	i = 0;
	while (*(file + i) != '\0')
		i++;
	return (i);
}

void	ft_put_err(void)
{
	write(1, "Error\n", 6);
}

int		ft_check_number(char *number)
{
	int i;

	i = 0;
	while (*(number + i) != '\0')
	{
		if (*(number + i) >= '0' && *(number + i) <= '9')
			i++;
		else if (*(number + i) != '\0')
		{
			ft_put_err();
			return (0);
		}
	}
	return (1);
}

int		ft_check_dict(char *dict)
{
	int i;
	int len;

	len = ft_strlen(dict);
	i = 0;
	if (dict[len - 1] == 't' && dict[len - 2] == 'c'
			&& dict[len - 3] == 'i' && dict[len - 4] == 'd'
			&& dict[len - 5] == '.')
	{
		return (1);
	}
	else
	{
		ft_put_err();
		return (0);
	}
}

int		ft_check_p(char *dict, char *number)
{
	if (number == NULL)
		return (ft_check_number(dict));
	else
	{
		if (ft_check_number(number) == 1)
			return (ft_check_dict(dict));
	}
	return (0);
}
