/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_choice.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 13:52:12 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 18:49:33 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header.h"

int		empty_buffer(void)
{
	int c;

	c = 0;
	while (c != '\n' && c != EOF)
		c = getchar();
	return (0);
}

int		ft_strchr(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
			str[i] = 0;
		i++;
	}
	return (1);
}

int		test_stdin(char *str, int choice_max)
{
	if (str[1] != 0)
	{
		empty_buffer();
		return (0);
	}
	while ((str[0] - 48) != choice_max)
	{
		if (choice_max == 0)
		{
			empty_buffer();
			return (0);
		}
		choice_max--;
	}
	return (1);
}

int		choice(char *str, int size, int choice_max, char *print)
{
	int test_bug;

	test_bug = 0;
	while (test_bug != 1)
	{
		if (print != 0)
			printf("%s : ", print);
		if (fgets(str, size, stdin) != NULL)
		{
			ft_strchr(str, '\n');
			if (str[0] != 0 && str[0] - 48 <= choice_max && str[1] == 0)
				test_bug = 1;
			else if (str[0] != 0)
				empty_buffer();
		}
	}
	return (1);
}

void	print(char *str)
{
	char enter;

	enter = 0;
	printf("%s", str); 
	while (enter != '\n' && enter != '\r')
		enter = getchar();
}
