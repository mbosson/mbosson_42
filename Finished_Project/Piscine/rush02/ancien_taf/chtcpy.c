/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   while.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/17 15:02:03 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/17 17:08:25 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i - 1);
}

int chestplate(char *number)
{
	int i;
	int count;

	i =	ft_first_group(number);
	count = strlen(number) - i;
	if (ft_write(number) == 0)
	{
		while (number[i])
		{
			write_three(number[i], number[i + 1], number[i + 2]);
			i += 3;
			if (count == 11)
				ft_write(sep1);
			if (count == 8)
				ft_write(sep2);
			if (count == 5)
				ft_write(sep3);
			count -= 3;
		}
	}
}

int modulo_three(char *number)
{
	int len;

	len = strlen(number);
	return (len % 3);
}

int ft_first_group(char *number)
{
	int m;
	int i;

	i = 0;
	m = modulo_three(number);
	if (m == 2)
		write_dec(number[0], number[1]);
	if (m == 1)
		write_un(number[0]);
	return (m)
}
