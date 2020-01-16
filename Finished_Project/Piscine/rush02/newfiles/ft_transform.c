/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_transform.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/17 21:22:36 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/08/17 21:31:06 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header.h"

char            *ft_calloc(int num)
{
	char *tab;
	int i;
	i = 0;
	tab = malloc(num * sizeof(char));
	while (i < num)
		tab[i++] = 0;
	return (tab);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (*(dest + i) != '\0')
	{
		i++;
	}
	while (*(src + j) != '\0')
	{
		*(dest + i + j) = *(src + j);
		j++;
	}
	*(dest + i + j) = *(src + j);
	return (dest);
}

int		ft_empty_file(char *file)
{
	int fd;
	char *buff;
	int sz;

	fd = open(file, O_RDWR);
	buff = (char *)ft_calloc((1));
	sz = read(fd, buff, 1);
	if (sz <= 0)
		return (ft_dict_error());
	else
		return (1);
}


char *ft_transf(char *file)
{
	int fd;
	int sz;
	char *buff;
	char *giant;
	char *tampon;
	int compt;

	compt = 1;
	if (ft_empty_file(file) == 0)
		return (0);
	fd = open(file, O_RDWR);
	giant = (char *)ft_calloc(100 * compt + 1);
	sz = 1;
	while (sz > 0)
	{
		buff = (char *)ft_calloc((100 * compt + 1));
		sz = read(fd, buff, compt * 100);
		buff[compt * 100] = '\0';
		tampon = (char *)ft_calloc((compt * 100 + 1));
		tampon = ft_strcat(tampon, giant);
		free(giant);
		giant = ft_calloc(((compt + 1) * 100 + 1));
		giant = ft_strcat(giant, tampon);
		giant = ft_strcat(giant, buff);
		free(buff);
		free(tampon);
		giant[compt * 100] = '\0';
		compt++;
	}
	close(fd);
	return (giant);
}


/*
   int		space_erase(char *giant)
   {
   int compt;

   compt = 0;
   if(giant[i])
   {
   if(giant[i] != '\n')
   {
   while (giant[i] >= '0' && giant[i] <= '9' && giant[i] != '\0')
   i++;
   while (giant[i] == ' ' && giant[i] != '\0')
   i++;
   i++;
   while (giant[i] == ' ' && giant[i] != '\0')
   i++;
   end = i;
   while (giant[i] >= 32 && giant[i] != '\0')
   i++;
   compt++;
   }
   i++;
   }
   return (compt);
   }

   char *modif(char *giant, int start, int end)
   {

   }*/	
