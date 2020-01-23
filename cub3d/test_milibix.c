/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_milibix.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 15:21:41 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 17:56:53 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "Minilibix/mlx.h"

int ft_print_pixel(void *mlx_ptr, void *win_ptr, unsigned int color)
{
	int		x = 0;
	int		x_buff = x;
	int		y = 0;
//	int		y_buff = y;

	while (y < 420)
	{
		x = x_buff;
		while (x < 699)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
			color++;
			x++;
		}
		y++;
	}
	return (0);
}

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		(*pf)(void *, void *, unsigned int);
	unsigned int color = 0x00000000;

	pf = ft_print_pixel;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 700, 420, "Francois Hollande ce duc");
	ft_print_pixel(mlx_ptr, win_ptr, color++);
	mlx_key_hook(win_ptr, pf, (void *)13);
	mlx_loop(mlx_ptr);
	return (0);
}
