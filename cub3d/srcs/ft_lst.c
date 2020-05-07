/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:21:05 by pbie              #+#    #+#             */
/*   Updated: 2015/12/02 19:04:11 by pbie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_lstadd(t_remindsprite **alst, t_remindsprite *new)
{
	if (new != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}

void		ft_lstdel(t_remindsprite **alst)
{
	t_remindsprite	*tmp;
	t_remindsprite	*next;

	tmp = *alst;
	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*alst = NULL;
}
