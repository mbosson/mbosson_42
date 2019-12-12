/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 13:53:42 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 17:55:04 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	redirection(va_list argument, t_list *convert)
{
	if (convert->spe == 'c')
		return (convertion_char(argument, convert));
	if (convert->spe == 's')
		return (convert_redirection(convert, va_arg(argument, char *)));
	if (convert->spe == 'p')
		return (convert_redirection(convert, ft_itoa_base(va_arg(argument, unsigned long int), "0123456789abcdef")));
	if (convert->spe == 'd' || convert->spe == 'i')
		return (convert_redirection(convert, ft_itoa(va_arg(argument, int))));
	if (convert->spe == 'u')
		return (convert_redirection(convert, ft_itoa(va_arg(argument, unsigned int))));
	if (convert->spe == 'x')
		return (convert_redirection(convert, ft_itoa_base(va_arg(argument, unsigned int), "0123456789abcdef")));
	if (convert->spe == 'X')
		return (convert_redirection(convert, ft_itoa_base(va_arg(argument, unsigned int), "0123456789abcdef")));
	if (convert->spe == '%')
		return (write(1, "%", 1));
	return (1);
}

int	parsing(t_list *convert, va_list argument, const char *str, int *i)
{
	set_conv_null(convert);
	*i += 1;
	while (str[*i] == '0' || str[*i] == '-')
	{
		convert->flag = str[*i];
		*i += 1;
	}
	if (ft_isdigit(str[*i]) == 1)
		convert->width = ft_atoi(str, i);
	else if (str[*i] == '*')
	{
		convert->width = va_arg(argument, int);
		*i += 1;
	}
	if (str[*i] == '.')
		convert->prec = ft_atoi(str, i);
	else if (str[*i] == '*')
	{
		convert->prec = va_arg(argument, int);
		*i += 1;
	}
	convert->spe = str[*i];
	*i += 1;
	return (redirection(argument, convert));
}

int	ft_printf(const	char *str, ...)
{
	va_list	argument;
	int		i;
	t_list	*convert;

	if ((convert = malloc(sizeof(t_list) * 1)) == 0)
		return (-1);
	i = 0;
	convert->result = 0;
	va_start(argument, str);
	while (str[i] != 0)
	{
		if (str[i] == '%')
			if ((parsing(convert, argument, str, &i) == -1))
			{
				free(convert);
				return (-1);
			}
		convert->result += write(1, &str[i], 1);
		i++;
	}
	i = convert->result;
	printf("\nresult : %d\n", i);
	free(convert);
	return (i);
}
