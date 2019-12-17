/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_convertion.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 13:31:50 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 19:00:31 by mbosson     ###    #+. /#+    ###.fr     */
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
	if (n == -1)
		return (utils(convert, 0, 1));
	if (n > convert->prec)
		n = convert->prec;
	if (convert->width > n)
		j = convert->width - n;
	if (convert->spe == 'd' && convert->flag == '0' && str[0] == '-'
			&& convert->special == 1)
		convert->result += write(1, "-", ++i);
	while (j-- != 0)
		convert->result += write(1, &flag, 1);
	while (i < n)
		convert->result += write(1, &str[i++], 1);
	if (convert->spe == 'c' && str[0] == 0)
		write(1, "\0", 1);
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
	if (n == -1)
		return (utils(convert, 0, 1));
	if (n > convert->prec)
		n = convert->prec;
	if (convert->width > n)
		j = convert->width - n;
	if (convert->spe == 'c' && str[0] == 0)
		write(1, "\0", 1);
	while (i < n)
		convert->result += write(1, &str[i++], 1);
	while (j-- != 0)
		convert->result += write(1, &flag, 1);
	return (1);
}

int	convert_redirect_decimal(t_list *convert, char *str, char flag, int len)
{
	if (convert->prec == 0 && str[0] == 0)
	{
		convertion_str(convert, str, flag);
		return (ret_free(str, 1));
	}
	if (convert->prec < 0 && convert->flag == '0')
		utils(convert, &flag, 2);
	if (convert->prec < len)
		convert->prec = len;
	else if (convert->prec >= len)
	{
		if ((str = create_str_spe_superior(convert, str)) == NULL)
			return (ret_free(str, -1));
	}
	else if (flag == '0' && convert->width > len)
	{
		convert->prec = convert->width - 1;
		if ((str = create_str_spe_superior(convert, str)) == NULL)
			return (ret_free(str, -1));
	}
	if (convert->flag == '-')
		convertion_flag_str(convert, str, flag);
	else
		convertion_str(convert, str, flag);
	return (ret_free(str, 1));
}

int	convert_redirection(t_list *convert, char *str)
{
	char flag;

	flag = ' ';
	if (convert->spe == 'p')
		if ((str = put_ox(str)) == NULL)
			return (-1);
	if (convert->spe != 'c' && convert->spe != 's')
		return (convert_redirect_decimal(convert, str, flag, ft_strlen(str)));
	if (convert->prec < 0)
		convert->prec = ft_strlen(str);
	if (convert->flag == '0')
		flag = '0';
	if (convert->flag == '-')
		return (convertion_flag_str(convert, str, flag));
	return (convertion_str(convert, str, flag));
}
