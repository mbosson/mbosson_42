/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d_set_key_hook.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/27 13:26:25 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/18 17:05:37 by mbosson          ###   ########lyon.fr   */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_hook(t_struct *bag)
{
	float angle;
	char **map;
	static float speed = SPEED;
	int colX;
	int lineY;

	map = bag->map->map;
	colX = (int)(bag->player->x / 64);
	lineY = (int)(bag->player->y / 64);
	if (bag->key->esc == 1)
		exit(1);
	angle = bag->player->dir;
	if (bag->key->shift == 1 && speed < SPEED * 3)
		speed += speed / 20;
	if (bag->key->shift == 0 && speed > SPEED)
		speed -= speed / 20;
	if (bag->key->w == 1)
	{
		if (map[lineY][(int)((bag->player->x + cos(bag->player->dir) * speed) / 64)] != '1')
			bag->player->x += cos(bag->player->dir) * speed;
		if (map[(int)((bag->player->y - sin(bag->player->dir) * speed) / 64)][colX] != '1')
			bag->player->y -= sin(bag->player->dir) * speed;
		ray_tracing(bag);
	}
	else if (bag->key->s == 1)
	{
		if (map[lineY][(int)((bag->player->x - cos(bag->player->dir) * speed) / 64)] != '1')
			bag->player->x -= cos(bag->player->dir) * speed;
		if (map[(int)(((bag->player->y + sin(bag->player->dir) * speed) / 64))][colX] != '1')
			bag->player->y += sin(bag->player->dir) * speed;
		ray_tracing(bag);
	}
	if (bag->key->d == 1)
	{
		if (angle - M_PI_2 < 0)
			angle = (M_PI * 2) + angle - M_PI_2;
		else
			angle = angle - M_PI_2;
		if (map[lineY][(int)((bag->player->x + cos(angle) * speed) / 64)] != '1')
			bag->player->x += cos(angle) * speed;
		if (map[(int)((bag->player->y - sin(angle) * speed) / 64)][colX] != '1')
			bag->player->y -= sin(angle) * speed;
		ray_tracing(bag);
	}
	if (bag->key->a == 1)
	{
		if (angle - M_PI_2 < 0)
			angle = (M_PI * 2) + angle - M_PI_2;
		else
			angle = angle - M_PI_2;
		if (map[lineY][(int)((bag->player->x - cos(angle) * speed) / 64)] != '1')
			bag->player->x -= cos(angle) * speed;
		if (map[(int)((bag->player->y + sin(angle) * speed) / 64)][colX] != '1')
			bag->player->y += sin(angle) * speed;
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

int	key_press(int key, t_struct *bag)
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
	if (key == SHIFT)
		bag->key->shift = 1;
	return (1);
}

int	key_unpress(int key, t_struct *bag)
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
	if (key == SHIFT)
		bag->key->shift = 0;
	return (1);
}
