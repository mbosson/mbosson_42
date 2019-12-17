/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_utils_decimal.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 15:42:57 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 19:01:00 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*create_str_spe_superior(t_list *convert, char *str)
{
	char	*str2;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	if ((str2 = malloc(sizeof(char) * (convert->prec + 2))) == 0)
		return (NULL);
	if (str[0] == '-')
	{
		str2[0] = '-';
		i++;
		j++;
		convert->prec++;
	}
	while (i - j < convert->prec - len)
		str2[i++] = '0';
	while (str[j] != 0)
		str2[i++] = str[j++];
	str2[i] = 0;
	free(str);
	return (str2);
}

char	*put_ox(char *str)
{
	char	*str2;
	int		i;
	int		j;
	int		len;

	i = 2;
	j = 0;
	len = ft_strlen(str);
	if ((str2 = malloc(sizeof(char) * (len + 3))) == 0)
		return (NULL);
	str2[0] = '0';
	str2[1] = 'x';
	while (str[j] != 0)
		str2[i++] = str[j++];
	str2[i] = 0;
	free(str);
	return (str2);
}

char	*null_str(void)
{
	char *str;

	if ((str = malloc(sizeof(char) * 2)) == 0)
		return (NULL);
	str[0] = 0;
	str[1] = 0;
	return (str);
}

int		utils(t_list *convert, char *flag, int choice)
{
	if (convert->spe == 's' && choice == 1)
		convert_redirection(convert, "(null)");
	else if (choice == 2)
	{
		*flag = '0';
		convert->special = 1;
	}
	return (0);
}

int		ret_free(void *str, int ret)
{
	free(str);
	return (ret);
}
