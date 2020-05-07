/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d_utils_2.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/12 22:30:01 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/27 15:49:28 by mbosson          ###   ########lyon.fr   */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

void	remind_sprite(t_struct *bag, t_remindsprite *reminder, int column, double longeur, double Wall_x)
{
	t_remindsprite *actual;
	t_remindsprite *new;

	actual = reminder;
	while (actual->next != 0)
		actual = actual->next;
	actual->column = column;
	actual->longeur = longeur;
	actual->Wall_x = Wall_x;
	if ((new = malloc(sizeof(t_remindsprite) * 1)) == 0)
		exit(1);
	new->next = 0;
	actual->next = new;
}

unsigned int random_hexa(void)
{
  unsigned int   nb;

  nb = 0;
  srand(time(0) * getpid());
  nb = rand() % 1000000;
  return (nb);
}

int	ft_is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int result;
	int p_or_n;
	int i;

	p_or_n = 1;
	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-')
		p_or_n = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (ft_is_num(str[i]) == 1)
		result = str[i] - 48;
	else
		return (0);
	i++;
	while (str[i] && ft_is_num(str[i]) == 1)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result * p_or_n);
}
