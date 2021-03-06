/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_choice.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 13:52:12 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 17:44:36 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header.h"

int		empty_buffer(void)
{
	int c;

	c = 0;
	while (c != '\n' && c != EOF && c != '\r')
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

int		choice(char *print, int choice_max)
{
	int test_bug;

	test_bug = 0;
	while (test_bug != 1)
	{
		if (print != 0)
			printf("%s : ", print);
		if (fgets(chemin, 3, stdin) != NULL)
		{
			
			ft_strchr(chemin, '\n');
			if (chemin[0] != 0 && (chemin[0] - 48) <= choice_max && chemin[0] >= '1' && chemin[1] == 0)
				test_bug = 1;
			else if (chemin[0] != 0 && chemin[1] != 0)
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
