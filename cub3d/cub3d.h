/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/15 14:54:21 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/12 22:46:13 by mbosson     ###    #+. /#+    ###.fr     */
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
# define SHIFT			257
# define SPEED			5

# include "srcs/get_next_line/get_next_line.h"
# include "mlx/mlx.h"
# include <stdio.h>
# include <limits.h>
# include <strings.h>
# include <math.h>

typedef struct	s_map				//MAP
{
	int			tabheight; // ^
	int			tabwidth;  // >
	char		**map;
}				t_map;

typedef	struct	s_player				//PLAYER
{
	double				x;
	double				y;
	float				dir;
}				t_player;

typedef struct	s_wall				//Wall / Calcul
{
	double		x;
	double		y;
	double		interX;
	double		interY;
	int			colX;
	int			lineY;
}				t_wall;

typedef struct	s_mlx				//MLX
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	unsigned int	*data;
}				t_mlx;

typedef	struct	s_raycasting				//VALEUR RAYTRACING
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
}				t_raycasting;

typedef struct	s_key
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
	int			shift;
}				t_key;

typedef struct s_pars
{
	char			*path_no;
	char			*path_so;
	char			*path_we;
	char			*path_ea;
	char			*path_s;
	unsigned int	color_floor;
	unsigned int	color_celling;
	int				width;
	int				height;
}				t_pars;

typedef struct	s_struct
{
	t_player		*player;
	t_map			*map;
	t_mlx			*mlx;
	t_key			*key;
	t_pars			*pars;
}				t_struct;

void			clear_wall(unsigned int *data);
char			*ft_strdup(char *s1);
char			*ft_itoa(int n);
t_map			*parsing(char *file, t_struct *bag);
int				ft_isalpha(int c);
int				ft_is_num(char c);
int				ft_strlen(char *str);
int				ft_atoi(char *str);
int				tablen(char **tab);
int				set_player(t_struct *bag);
int				ray_tracing(t_struct *bag);
int				key_hook(t_struct *bag);
int				key_press(int key, t_struct *bag);
int				key_unpress(int key, t_struct *bag);
double			find_wall_horizontal(t_player *player, t_map *map, t_raycasting raycasting);
double			find_wall_vertical(t_player *player, t_map *map, t_raycasting raycasting);
double			whose_higher(t_raycasting *raycasting);
t_mlx			*set_libx(void);
t_struct		*set_struct(char *file);
void			draw_wall(t_raycasting raycasting, t_mlx *mlx, double dist_to_wall);

#endif
