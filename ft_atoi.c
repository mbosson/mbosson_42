/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 09:53:08 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 15:35:18 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int result;
	int p_or_n;
	int i;

	p_or_n = 1;
	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-')
		p_or_n = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (ft_isdigit(str[i]) == 1)
		result = str[i] - 48;
	else
		return (0);
	i++;
	while (str[i] && ft_isdigit(str[i]) == 1)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result * p_or_n);
}
