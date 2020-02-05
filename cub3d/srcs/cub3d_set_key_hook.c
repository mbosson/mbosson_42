/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d_set_key_hook.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/27 13:26:25 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 16:17:29 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

//cos -> x
//sin -> y

#include "../cub3d.h"

int	key_hook(d_list *bag)
{
	float angle;

	if (bag->key->esc == 1)
		exit(1);
	angle = bag->player->dir;
	if (bag->key->w == 1)
	{
		if ((bag->player->x + cos(bag->player->dir) * SPEED) < bag->map->tabwidth * 64)
			bag->player->x += cos(bag->player->dir) * SPEED;
		if ((bag->player->y - sin(bag->player->dir) * SPEED) < bag->map->tabheight * 64)
			bag->player->y -= sin(bag->player->dir) * SPEED;
		ray_tracing(bag);
	}
	if (bag->key->s == 1)
	{
		bag->player->x -= cos(bag->player->dir) * SPEED;
		bag->player->y += sin(bag->player->dir) * SPEED;
		ray_tracing(bag);
	}
	if (bag->key->d == 1)
	{
		if (angle - M_PI_2 < 0)
			angle = (M_PI * 2) + angle - M_PI_2;
		else
			angle = angle - M_PI_2;
		bag->player->x += cos(angle) * SPEED;
		bag->player->y -= sin(angle) * SPEED;
		ray_tracing(bag);
	}
	if (bag->key->a == 1)
	{
		if (angle - M_PI_2 < 0)
			angle = (M_PI * 2) + angle - M_PI_2;
		else
			angle = angle - M_PI_2;
		bag->player->x -= cos(angle) * SPEED;
		bag->player->y += sin(angle) * SPEED;
		ray_tracing(bag);
	}
	if (bag->key->right == 1)
	{
		bag->player->dir -= 0.05;
		if (bag->player->dir < 0)
			bag->player->dir += M_PI * 2;
		ray_tracing(bag);
	}
	if (bag->key->left == 1)
	{
		bag->player->dir += 0.05;
		if (bag->player->dir > M_PI * 2)
			bag->player->dir -= M_PI * 2;
		ray_tracing(bag);
	}
	return (1);
}

int	key_press(int key, d_list *bag)
{
	if (key == ESC)
		bag->key->esc = 1;
	if (key == W)
		bag->key->w = 1;	
	if (key == S)
		bag->key->s = 1;
	if (key == D)
		bag->key->d = 1;
	if (key == A)
		bag->key->a = 1;
	if (key == LEFT)
		bag->key->left = 1;
	if (key == RIGHT)
		bag->key->right = 1;
	if (key == FRONT)
		bag->key->up = 1;
	if (key == BACK)
		bag->key->down = 1;
	return (1);
}

int	key_unpress(int key, d_list *bag)
{
	if (key == W)
		bag->key->w = 0;	
	if (key == S)
		bag->key->s = 0;
	if (key == D)
		bag->key->d = 0;
	if (key == A)
		bag->key->a = 0;
	if (key == LEFT)
		bag->key->left = 0;
	if (key == RIGHT)
		bag->key->right = 0;
	if (key == FRONT)
		bag->key->up = 0;
	if (key == BACK)
		bag->key->down = 0;
	return (1);
}
