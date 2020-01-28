/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d_hearth.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 08:39:25 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 16:43:44 by mbosson     ###    #+. /#+    ###.fr     */
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
	printf("tabheight : %d\n\n", bag->map->tabheight);
	printf("tabwidth : %d\n\n", bag->map->tabwidth);
	printf("player.x : %d\nplayer.y : %d\n", bag->player->x / 64, bag->player->y / 64);
	mlx_hook(bag->mlx->win_ptr, 2, 0, key_hook, bag);
	//ray_tracing(bag);
	mlx_loop(bag->mlx->mlx_ptr);
}
