/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d_hearth.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 08:39:25 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 16:33:04 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int argc, char **argv)
{
	d_list	*bag;

	if (argc > 2)
		return (write(1, "Too much arguments.", 19));
	bag = set_struct(argv[1]);
	printf("player.x : %f\nplayer.y : %f\n", bag->player->x / 64, bag->player->y / 64);
	mlx_hook(bag->mlx->win_ptr, 2, 0, key_press, bag);
	mlx_hook(bag->mlx->win_ptr, 3, 0, key_unpress, bag);
	mlx_loop_hook(bag->mlx->mlx_ptr, key_hook, bag);
	mlx_loop(bag->mlx->mlx_ptr);
}
