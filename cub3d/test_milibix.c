/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_milibix.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 15:21:41 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 10:00:33 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "Minilibix/mlx.h"

int ft_print_pixel(void *tab_ptr)
{
	int		x = 0;
	int		x_buff = x;
	int		y = 0;
//	int		y_buff = y;
	unsigned int color = 0x0000000;

	while (y < 900)
	{
		x = x_buff;
		while (x < 699)
		{
			mlx_pixel_put(tab_ptr[0], tab_ptr[1], x, y, color);
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
	void	*img_ptr;
	void	*tab_ptr[2];

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 700, 420, "Francois Hollande ce duc");
	tab_ptr[0] = mlx_ptr;
	tab_ptr[1] = win_ptr;
	ft_print_pixel(tab_ptr);
	mlx_key_hook(win_ptr, ft_print_pixel, tab_ptr);
	mlx_loop(mlx_ptr);
	return (0);
}
