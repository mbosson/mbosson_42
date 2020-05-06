/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d_set_key_hook.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/27 13:26:25 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/27 17:09:41 by mbosson          ###   ########lyon.fr   */
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
	colX = (int)(bag->player->x / CUBE_SIZE);
	lineY = (int)(bag->player->y / CUBE_SIZE);
	if (bag->key->esc == 1)
		exit(1);
	angle = bag->player->dir;
	if (bag->key->p == 1)
	{
		bag->pars->color_psy += random_hexa();
		if (bag->fov_deg < 160)
			bag->fov_deg += 1;
		ray_tracing(bag);
	}
	else if (bag->key->c == 1)
	{
		bag->pars->color_psy = 0;
		bag->fov_deg = FOV_DEG;
		ray_tracing(bag);
	}
	if (bag->key->shift == 1 && speed < SPEED * 3)
		speed += speed / 20;
	if (bag->key->shift == 0 && speed > SPEED)
		speed -= speed / 20;
	if (bag->key->up == 1 && bag->player->middle_of_screen + speed < bag->pars->height)
	{
		bag->player->middle_of_screen += speed;
		ray_tracing(bag);
	}
	if (bag->key->down == 1 && bag->player->middle_of_screen - speed > 0)
	{
		bag->player->middle_of_screen -= speed;
		ray_tracing(bag);
	}
	if (bag->key->d == 1)
	{
		if (angle - M_PI_2 < 0)
			angle = (M_PI * 2) + angle - M_PI_2;
		else
			angle = angle - M_PI_2;
		if (map[lineY][(int)((bag->player->x + cos(angle) * speed) / CUBE_SIZE)] != '1')
			bag->player->x += cos(angle) * speed;
		if (map[(int)((bag->player->y - sin(angle) * speed) / CUBE_SIZE)][colX] != '1')
			bag->player->y -= sin(angle) * speed;
		ray_tracing(bag);
	}
	if (bag->key->a == 1)
	{
		if (angle - M_PI_2 < 0)
			angle = (M_PI * 2) + angle - M_PI_2;
		else
			angle = angle - M_PI_2;
		if (map[lineY][(int)((bag->player->x - cos(angle) * speed) / CUBE_SIZE)] != '1')
			bag->player->x -= cos(angle) * speed;
		if (map[(int)((bag->player->y + sin(angle) * speed) / CUBE_SIZE)][colX] != '1')
			bag->player->y += sin(angle) * speed;
		ray_tracing(bag);
	}
	if (map[lineY][(int)((bag->player->x + cos(bag->player->dir) * speed) / CUBE_SIZE)] != '1')
		bag->player->x += cos(bag->player->dir) * speed;
	else
		exit(1);
	if (map[(int)((bag->player->y - sin(bag->player->dir) * speed) / CUBE_SIZE)][colX] != '1')
		bag->player->y -= sin(bag->player->dir) * speed;
	else
		exit(1);
	ray_tracing(bag);
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
	if (key == P)
		bag->key->p = 1;
	if (key == C)
		bag->key->c = 1;
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
	if (key == P)
		bag->key->p = 0;
	if (key == C)
		bag->key->c = 0;
	return (1);
}
