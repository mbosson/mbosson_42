/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/13 15:06:18 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/14 14:18:26 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (dest[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *ft_strdup(char *src)
{
	char *ptr;

	ptr = malloc(sizeof(char) * (sizeof(src) + 1);
	ft_strcpy(ptr, src);
	return (ptr);
}
