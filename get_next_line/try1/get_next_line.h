/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 10:08:18 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 10:49:58 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 2
# endif

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		get_next_line(int fd, char **line);
int     ft_read(int fd, char **line, int size, char **remainder);
int     ft_emptyfile(int fd, char **remainder, int size, char **line);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
int     usefull_free(char **str1, int val_ret);
#endif
