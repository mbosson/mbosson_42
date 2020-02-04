/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d_set_key_hook.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/27 13:26:25 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 15:33:57 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

//cos -> x
//sin -> y

#include "../cub3d.h"

int	key_hook(int key, d_list *bag)
{
	float angle;

	angle = bag->player->dir;
	if (key == ESC)
		exit(1);
	else if (key == W)
	{
		if ((bag->player->x + cos(bag->player->dir) * SPEED) < bag->map->tabwidth * 64)
			bag->player->x += cos(bag->player->dir) * SPEED;
		if ((bag->player->y - sin(bag->player->dir) * SPEED) < bag->map->tabheight * 64)
			bag->player->y -= sin(bag->player->dir) * SPEED;
		ray_tracing(bag);
	}
	else if (key == S)
	{
		bag->player->x -= cos(bag->player->dir) * SPEED;
		bag->player->y += sin(bag->player->dir) * SPEED;
		ray_tracing(bag);
	}
	else if (key == D)
	{
		if (angle - M_PI_2 < 0)
			angle = (M_PI * 2) + angle - M_PI_2;
		else
			angle = angle - M_PI_2;
		bag->player->x += cos(angle) * SPEED;
		bag->player->y -= sin(angle) * SPEED;
		ray_tracing(bag);
	}
	else if (key == A)
	{
		if (angle - M_PI_2 < 0)
			angle = (M_PI * 2) + angle - M_PI_2;
		else
			angle = angle - M_PI_2;
		bag->player->x -= cos(angle) * SPEED;
		bag->player->y += sin(angle) * SPEED;
		ray_tracing(bag);
	}
	else if (key == RIGHT)
	{
		bag->player->dir -= 0.05;
		if (bag->player->dir < 0)
			bag->player->dir += M_PI * 2;
		ray_tracing(bag);
	}
	else if (key == LEFT)
	{
		bag->player->dir += 0.05;
		if (bag->player->dir > M_PI * 2)
			bag->player->dir -= M_PI * 2;
		ray_tracing(bag);
	}
	return (1);
}
