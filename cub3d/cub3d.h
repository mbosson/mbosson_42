/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/15 14:54:21 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 17:34:24 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define FOV_DEG		60
# define WIDHT_ECRAN	320
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
# include <stdio.h>
# include <limits.h>
# include <strings.h>
# include <math.h>

typedef struct	k_list
{
	int			tabheight; // >
	int			tabwidth;  // ^
	char		**map;
}				m_list;

typedef	struct	s_list
{
	long		x;
	long		y;
	float		dir;
}				t_list;

typedef struct	v_list
{
	long		x;
	long		y;
	long		interX;
	long		interY;
	long		colX;
	long		lineY;
}				c_list;

typedef struct	u_list
{
	void		*mlx_ptr;
	void		*win_ptr;
}				l_list;

char			*ft_strdup(char *s1);
m_list			*parsing(char *file);
int				ft_isalpha(int c);
int				ft_strlen(char *str);
int				tablen(char **tab);
long			find_wall_horizontal(t_list *player, m_list *map);
long			find_wall_vertical(t_list *player, m_list *map);
t_list			*set_player(char **map);

#endif
