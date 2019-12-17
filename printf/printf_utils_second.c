/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_utils_second.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 10:29:15 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 17:34:54 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		convertion_char(va_list argument, t_list *convert)
{
	char				c;
	char				str[2];

	if (convert->spe == 'c')
		c = va_arg(argument, int);
	else
	{
		convert->spe = 'c';
		c = '%';
	}
	if (convert->prec == 0)
		convert->prec++;
	str[0] = c;
	str[1] = 0;
	if (c == 0)
	{
		convert->width -= 1;
		convert->result++;
	}
	if (convert_redirection(convert, str) == -1)
		return (-1);
	return (1);
}

char	*calcul_base(unsigned long int number, char *base, int leng, int count)
{
	char *result;

	if ((result = malloc(sizeof(char) * (count + 1))) == 0)
		return (NULL);
	result[count--] = 0;
	while (number > (unsigned long int)leng - 1)
	{
		result[count--] = base[number % leng];
		number = number / leng;
	}
	result[count--] = base[number];
	return (result);
}

char	*ft_itoa_base(unsigned long int number, char *base, t_list *convert)
{
	int					leng;
	int					count;
	unsigned long int	buff;
	char				*result;

	if (number == 0 && convert->prec == 0)
		return (result = null_str());
	leng = ft_strlen(base);
	buff = number;
	count = 1;
	while (buff > (unsigned long int)leng - 1)
	{
		buff = buff / leng;
		count++;
	}
	return (calcul_base(number, base, leng, count));
}

char	*ft_complete(char *result, long int n, int count, int p_or_n)
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

char	*ft_itoa(long int n, t_list *convert)
{
	int					count;
	int					p_or_n;
	char				*result;
	long int			buff;

	if (n == 0 && convert->prec == 0)
		return (null_str());
	count = 0;
	p_or_n = 0;
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
