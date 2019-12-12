/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 08:08:43 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 17:43:55 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_conv_null(t_list *convert)
{
	convert->flag = (char)NULL;
	convert->width = -1;
	convert->prec = -1;
	convert->spe = (char)NULL;
}

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_isdigit(char c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

int		ft_atoi(const char *str, int *i)
{
	int result;
	int p_or_n;

	p_or_n = 1;
	result = 0;
	if (str[*i] == '.')
		*i += 1;
	while (str[*i] && ft_isdigit(str[*i]) == 1)
	{
		result *= 10;
		result += str[*i] - 48;
		*i += 1;
	}
	return (result * p_or_n);
}

int		ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
