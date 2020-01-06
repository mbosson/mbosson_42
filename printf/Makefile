# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/16 10:16:55 by mbosson      #+#   ##    ##    #+#        #
#    Updated: 2019/12/19 18:03:51 by mbosson     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

#VALUE

NAME		=	libftprintf.a

SRCS		=	printf.c				\
				print_convertion.c		\
				printf_utils.c			\
				printf_utils_second.c	\
				printf_utils_third.c	

OBJS		=	$(SRCS:.c=.o)

CC			=	@ gcc

CFLAGS		=	-Wall -Werror -Wextra

LIB			=	ft_printf.h

#RULE

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				 @ ar rc $(NAME) $(OBJS) $(LIB)
				 @ ranlib $(NAME)
				 @ echo $(NAME) created

clean		:	
				rm -f $(OBJS)

fclean		:	clean
				@ rm -f $(NAME)

re			:	fclean all

norm		:
				@ norminette $(SRCS) $(LIB)

%.o			:	%.c $(LIB)
				$(CC) -c -o $@ $< $(CFLAGS)

.PHONY		:	clean fclean
