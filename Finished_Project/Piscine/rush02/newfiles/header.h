/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   header.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/17 21:11:31 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/17 21:30:12 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef HEADER
# define HEADER

int		ft_check_p(char *dict, char *number);
void	ft_put_err(void);
int		ft_dict_err(void);
int		ft_write(int number);
void	arthur(int number);
int		ft_find_closest(int number);
int		ft_atoi(char *str);
int		ft_check_file(char *giant, int i);
char	*ft_transf(char *file);

#include <unistd.h>
#include <stdlib.h>

// ATTENTION A SUPPRIMER vv

#include <stdio.h>

#endif
