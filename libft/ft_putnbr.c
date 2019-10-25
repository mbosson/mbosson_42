/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 11:01:47 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/25 16:12:07 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putnbr(int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(48 + n % 10);
	}
	else if (0 <= n && n < 10)
		ft_putchar(48 + n % 10);
	else
	{
		ft_putchar('-');
		if (n <= -10)
			ft_putnbr(-(n / 10));
		ft_putchar(48 - n % 10);
	}
}
