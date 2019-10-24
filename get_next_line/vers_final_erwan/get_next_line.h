/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ermartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 13:24:56 by ermartin     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 16:48:32 by ermartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include<sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

typedef	struct	s_list
{
	int				fd;
	char			*remind;
	struct s_list	*next;
}				t_list;

int				get_next_line(int fd, char **line);
char			*ft_gnl_strdup(char **s1);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_lstclear(t_list **lst, int return_value);
void			*ft_calloc(size_t count);

#endif
