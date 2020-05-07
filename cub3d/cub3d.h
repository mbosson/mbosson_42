/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/15 14:54:21 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/27 17:09:43 by mbosson          ###   ########lyon.fr   */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define FOV_DEG		60
# define CUBE_SIZE		64
# define SPEED			7
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
# define P				35
# define C				8

# include "srcs/get_next_line/get_next_line.h"
# include "mlx/mlx.h"
# include <stdio.h>
# include <limits.h>
# include <strings.h>
# include <math.h>
# include <time.h>

typedef struct	s_remindsprite
{
	int			column;
	double			longeur;
	double			Wall_x;
	void			*next;
}				t_remindsprite;

typedef struct	s_map				//MAP
{
	int			tabheight; // ^
	int			tabwidth;  // >
	char		**map;
	double			Wall_x;
	double			Wall_y;
	int				ori_wall;
}				t_map;

typedef	struct	s_player				//PLAYER
{
	double				x;
	double				y;
	int					colX;
	int					lineY;
	float				dir;
	int					middle_of_screen;
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
	double					ray;
	float					inter_ray;
	float					last_ray;
	double					dist_to_screen;
	float					FOV;
	float					bitmap_ratio;
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
	int			p;
	int			c;
}				t_key;

typedef struct s_pars
{
	char			*path_no;
	unsigned int		*no;
	char			*path_so;
	unsigned int		*so;
	char			*path_we;
	unsigned int		*we;
	char			*path_ea;
	unsigned int		*ea;
	char			*path_s;
	unsigned int		*s;
	unsigned int		*texture;
	unsigned int		color_floor;
	unsigned int		color_celling;
	unsigned int 	color_psy;
	int					width;
	int					height;
	int					width_no;
	int					height_no;
	int					width_so;
	int					height_so;
	int					width_ea;
	int					height_ea;
	int					width_we;
	int					height_we;
	int					width_s;
	int					height_s;
	int					texture_width;
	int					texture_height;
	double				texture_size;
}				t_pars;

typedef struct	s_struct
{
	t_player		*player;
	t_map			*map;
	t_mlx			*mlx;
	t_key			*key;
	t_pars			*pars;
	t_remindsprite		*reminder;
	int				fov_deg;
}				t_struct;

void			clear_wall(unsigned int *data, t_struct *bag);
void			remind_sprite(t_struct *bag, t_remindsprite *reminder, int column, double longeur, double Wall_x);
void			print_sprite(t_struct *bag, t_raycasting raycasting);
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
unsigned int	random_hexa(void);
double			find_wall_horizontal(t_player *player, t_map *map, t_raycasting raycasting, t_struct *bag);
double			find_wall_vertical(t_player *player, t_map *map, t_raycasting raycasting, t_struct *bag);
double			whose_higher(t_raycasting *raycasting);
t_mlx			*set_libx(t_struct *bag);
t_struct		*set_struct(char *file);
void			draw_wall(t_raycasting raycasting, t_mlx *mlx, double dist_to_wall, t_struct *bag);

#endif
