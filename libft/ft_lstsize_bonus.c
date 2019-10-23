/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstsize_bonus.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 14:10:09 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 14:51:29 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*current;

	if (lst == 0)
		return (0);
	len = 0;
	current = lst;
	while (current->next)
	{
		len++;
		current = current->next;
	}
	len++;
	return (len);
}
