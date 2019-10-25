# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/16 11:04:58 by mbosson      #+#   ##    ##    #+#        #
#    Updated: 2019/10/25 16:11:44 by mbosson     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

#VALUE

NAME		=	libft.a

SRCS		=	ft_atoi.c				\
				ft_bzero.c				\
				ft_calloc.c				\
				ft_isalnum.c			\
				ft_isalpha.c			\
				ft_isascii.c			\
				ft_isdigit.c			\
				ft_isprint.c			\
				ft_itoa.c				\
				ft_memccpy.c			\
				ft_memchr.c				\
				ft_memcmp.c				\
				ft_memcpy.c				\
				ft_memmove.c			\
				ft_memset.c				\
				ft_putstr.c				\
				ft_putchar_fd.c			\
				ft_putendl_fd.c			\
				ft_putnbr_fd.c			\
				ft_putnbr.c				\
				ft_putstr_fd.c			\
				ft_split.c				\
				ft_strchr.c				\
				ft_strdup.c				\
				ft_strjoin.c			\
				ft_strlcat.c			\
				ft_strlcpy.c			\
				ft_strlen.c				\
				ft_strmapi.c			\
				ft_strncmp.c			\
				ft_strnstr.c			\
				ft_strrchr.c			\
				ft_strtrim.c			\
				ft_substr.c				\
				ft_tolower.c			\
				ft_toupper.c

BONUS		=	ft_lstadd_back_bonus.c	\
				ft_lstadd_front_bonus.c	\
				ft_lstlast_bonus.c		\
				ft_lstnew_bonus.c		\
				ft_lstsize_bonus.c

OBJS 		=	$(SRCS:.c=.o)

OBJS_BONUS	=	$(BONUS:.c=.o)

CC			=	gcc

CFLAGS 	   +=	-Wall -Werror -Wextra

LIB			= 	libft.h


#RULES

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				 ar rc $(NAME) $(OBJS) $(LIB)
				 ranlib $(NAME)

clean		:
				 rm -f $(OBJS) $(OBJS_BONUS)

fclean		:	clean 
				rm -f $(NAME)

re			:	fclean all

bonus		:	$(OBJS)	$(OBJS_BONUS)
				ar rc $(NAME) $(OBJS_BONUS) $(LIB)
				ranlib $(NAME)

norm		:	
				norminette *.c libft.h

%.o			:	%.c $(LIB)
				$(CC) -c -o $@ $< $(CFLAGS)

.PHONY		:	clean fclean
