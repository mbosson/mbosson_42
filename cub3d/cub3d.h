/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/15 14:54:21 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 14:52:52 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define FOV_DEG		60
# define HEIGHT_ECRAN	200
# define WIDTH_ECRAN	320
# define CUBE_SIZE		64
# define ESC			53
# define W				13
# define FRONT			126
# define A				0
# define LEFT			123
# define S				1
# define BACK			125
# define D				2
# define RIGHT			124

# include "srcs/get_next_line/get_next_line.h"
# include "mlx/mlx.h"
# include <stdio.h>
# include <limits.h>
# include <strings.h>
# include <math.h>

typedef struct	k_list				//MAP
{
	int			tabheight; // >
	int			tabwidth;  // ^
	char		**map;
}				m_list;

typedef	struct	s_list				//PLAYER
{
	long		x;
	long		y;
	float		dir;
}				t_list;

typedef struct	v_list				//CALCUL RAYTRACING
{
	long		x;
	long		y;
	long		interX;
	long		interY;
	long		colX;
	long		lineY;
}				c_list;

typedef struct	u_list				//MLX
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	unsigned int	*data;
}				l_list;

typedef	struct	j_list				//VALEUR RAYTRACING
{
	long		long_vertical;
	long		long_horizontal;
	float		FOV;
	float		inter_ray;
	float		last_ray;
	int			dist_to_screen;
	int			middle_of_screen;
}				r_list;

char			*ft_strdup(char *s1);
m_list			*parsing(char *file);
int				ft_isalpha(int c);
int				ft_strlen(char *str);
int				tablen(char **tab);
long			find_wall_horizontal(t_list *player, m_list *map);
long			find_wall_vertical(t_list *player, m_list *map);
long			whose_higher(r_list raycasting);
t_list			*set_player(char **map);
l_list			*set_libx(void);
void			draw_wall(r_list raycasting, l_list *mlx, long dist_to_wall, int column);

#endif
