/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 15:22:50 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 17:19:43 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_list
{
	char		flag;
	int			width;
	int			prec;
	char		spe;
	int			result;
}				t_list;

int				ft_printf(const char *str, ...);
int				ft_atoi(const char *str, int *i);
int				ft_isdigit(char c);
int				ft_isalpha(int c);
int				ft_strlen(const char *str);
int				convertion_char(va_list argument, t_list *convert);
int				convert_redirection(t_list *convert, char *str);
int				str_null(t_list *convert);
int				ret_free(void *str, int ret);
char			*ft_itoa(long int n, t_list *convert);
char			*ft_itoa_base(unsigned long int number,
		char *base, t_list *convert);
char			*create_str_spe_superior(t_list *convert, char *str);
char			*create_str_pointeur(t_list *convert, char *str);
char			*put_ox(char *str);
char			*null_str(void);
void			ft_putnbr(int n);
void			ft_putchar(char c);
void			set_conv_null(t_list *convert);

#endif
