/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 09:59:34 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 15:37:00 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_complete(char *result, int n, int count, int p_or_n)
{
	if (p_or_n == 1)
		result[0] = '-';
	result[count] = 0;
	count--;
	while (n > 9)
	{
		result[count] = n % 10 + 48;
		n = n / 10;
		count--;
	}
	result[count] = n % 10 + 48;
	return (result);
}

static	char	*ft_min_value(void)
{
	char	*result;

	if ((result = ft_strdup("-2147483648")) == 0)
		return (0);
	return (result);
}

char			*ft_itoa(int n)
{
	int		count;
	int		p_or_n;
	char	*result;
	int		buff;

	count = 0;
	p_or_n = 0;
	if (n == -2147483648)
		return (ft_min_value());
	if (n < 0)
	{
		p_or_n = 1;
		count = 1;
		n *= -1;
	}
	buff = n;
	while (buff > 9)
	{
		buff = buff / 10;
		count++;
	}
	count++;
	if ((result = malloc(sizeof(char) * (count + 1))) == 0)
		return (0);
	return (ft_complete(result, n, count, p_or_n));
}
