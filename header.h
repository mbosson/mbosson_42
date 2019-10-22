/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   header.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 13:06:50 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 17:42:43 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include <string.h>
# include <stdio.h>

char	chemin[3];
int		life;

int		choice(int size, int choice_max, char *print);
void	print(char *str);
int		reveil(void);
