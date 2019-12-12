/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_convertion.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 13:31:50 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 17:42:36 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	convertion_str(t_list *convert, char *str, char flag)
{
	int i;
	int j;
	int n;

	i = 0;
	j = 0;
	n = ft_strlen(str);
	if (n > convert->prec)
		n = convert->prec;
	if (convert->width > n)
		j = convert->width - n;
	if (convert->spe == 'd' && convert->flag == '0' && str[0] == '-')
	{
		write(1, "-", 1);
		i++;
	}
	while (j-- != 0)
		write(1, &flag, 1);
	while (i < n)
		write(1, &str[i++], 1);
	return (0);
}

int	convertion_flag_str(t_list *convert, char *str, char flag)
{
	int i;
	int j;
	int n;

	i = 0;
	j = 0;
	n = ft_strlen(str);
	if (n > convert->prec)
		n = convert->prec;
	if (convert->width > n)
		j = convert->width - n;
	while (i < n)
		write(1, &str[i++], 1);
	while (j-- != 0)
		write(1, &flag, 1);
	return (1);
}

int	convert_redirection_decimal(t_list *convert, char *str, char flag)
{
	int len;

	len = ft_strlen(str);
	if (convert->prec == -1 && convert->flag == '0')
		flag = '0';
	if (convert->prec < len)
		convert->prec = len;
	else if (convert->prec >= len)
		str = create_str_spe_superior(convert, str);
	else if (flag == '0' && convert->width > len)
	{
		convert->prec = convert->width - 1;
		str = create_str_spe_superior(convert, str);
	}
	if (convert->flag == '-')
		convertion_flag_str(convert, str, flag);
	else
		convertion_str(convert, str, flag);
	free(str);
	return (0);
}

int	convert_redirection(t_list *convert, char *str)
{
	char flag;

	flag = ' ';
	if (convert->spe == 'p')
		str = put_ox(str);
	if (convert->spe != 'c' && convert->spe != 's')
		return (convert_redirection_decimal(convert, str, flag));
	if (convert->prec == -1)
		convert->prec = ft_strlen(str);
	if (convert->flag == '0')
		flag = '0';
	if (convert->flag == '-')
		return (convertion_flag_str(convert, str, flag));
	return (convertion_str(convert, str, flag));
}
