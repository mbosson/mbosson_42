/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d_set_libx.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/23 17:56:06 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 14:59:53 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"


l_list	*set_libx(void)
{
	l_list	*libx;

	int		bpp;
	int		size_line;
	int		endian;
	if ((libx = malloc(sizeof(l_list) * 1)) == 0)
		return (0);
	libx->mlx_ptr = mlx_init();
	libx->win_ptr = mlx_new_window(libx->mlx_ptr, WIDTH_ECRAN, HEIGHT_ECRAN, "Cub3D");
	libx->img_ptr = mlx_new_image(libx->mlx_ptr, WIDTH_ECRAN, HEIGHT_ECRAN);
	libx->data = (unsigned int *)mlx_get_data_addr(libx->img_ptr, &bpp, &size_line, &endian);
	return (libx);
}
