/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/14 19:40:17 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/08/18 15:30:23 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int i2;

	i2 = 0;
	i = 0;
	while (dest[i] != '\0')
		i++;
	while (src[i2] != '\0')
	{
		dest[i + i2] = src[i2];
		i2++;
	}
	dest[i + i2] = src[i2];
	return (dest);
}

int		ft_strlen_ultimate(char **strs, int size)
{
	int i;
	int j;
	int compt;

	i = 0;
	j = 0;
	compt = 0;
	while (j < size)
	{
		while (strs[j][i] != '\0')
		{
			i++;
			compt++;
		}
		i = 0;
		j++;
	}
	return (compt);
}

char *ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char 	*final_tab;
	int		sep_size;

	i = 0;
	len = ft_strlen_ultimate(strs, size);
	while (sep[i] != '\0')
		i++;
	sep_size = i;
	i = 0;
	final_tab = malloc(sizeof(char) * len + sep_size * (size - 1));
	if (final_tab == NULL)
		return (0);
	while (i < size)
	{
		ft_strcat(final_tab, strs[i]);
		ft_strcat(final_tab, sep);
		i++;
	}
	ft_strcat(final_tab, strs[i]);
	final_tab[len + sep_size * (size - 1)] = '\0';
	return (final_tab);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	printf("%s\n", ft_strjoin(argc, argv, "--"));
	return 0;
}
