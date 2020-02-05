/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/05 14:49:13 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 16:25:55 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/15 14:54:21 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 14:42:52 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define FOV_DEG		55
# define WIDTH_ECRAN	1920
# define HEIGHT_ECRAN	1080
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
# define SPEED			5

# include "srcs/get_next_line/get_next_line.h"
# include "mlx/mlx.h"
# include <stdio.h>
# include <limits.h>
# include <strings.h>
# include <math.h>

typedef struct	k_list				//MAP
{
	int			tabheight; // ^
	int			tabwidth;  // >
	char		**map;
}				m_list;

typedef	struct	s_list				//PLAYER
{
	int				x;
	int				y;
	float			dir;
}				t_list;

typedef struct	y_list				//Wall
{
	int				x;
	int				y;
}					w_list;

typedef struct	v_list				//CALCUL RAYTRACING
{
	double		x;
	double		y;
	double		interX;
	double		interY;
	int			colX;
	int			lineY;
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
	double					long_vertical;
	double					long_horizontal;
	float					FOV;
	double					ray;
	float					inter_ray;
	float					last_ray;
	double					dist_to_screen;
	int						middle_of_screen;
	int						column;
	int						last_wall;
	unsigned int			color;
}				r_list;

typedef struct	o_list
{
	int			w;
	int			s;
	int			a;
	int			d;
	int			left;
	int			right;
	int			up;
	int			down;
	int			esc;
}				z_list;

typedef struct	p_list
{
	t_list		*player;
	m_list		*map;
	l_list		*mlx;
	z_list		*key;
}				d_list;

void			clear_wall(unsigned int *data);
char			*ft_strdup(char *s1);
char			*ft_itoa(int n);
m_list			*parsing(char *file);
int				ft_isalpha(int c);
int				ft_strlen(char *str);
int				tablen(char **tab);
int				set_player(d_list *bag);
int				ray_tracing(d_list *bag);
int				key_hook(d_list *bag);
int				key_press(int key, d_list *bag);
int				key_unpress(int key, d_list *bag);
double			find_wall_horizontal(t_list *player, m_list *map, r_list raycasting);
double			find_wall_vertical(t_list *player, m_list *map, r_list raycasting);
double			whose_higher(r_list *raycasting);
l_list			*set_libx(void);
d_list			*set_struct(char *file);
void			draw_wall(r_list raycasting, l_list *mlx, double dist_to_wall);

#endif
