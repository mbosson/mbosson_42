/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   header.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 13:06:50 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 17:45:48 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include <string.h>
# include <stdio.h>

char	chemin[3];
int		life;

int		choice(char *print, int choice_max);
void	print(char *str);
int		reveil(void);
