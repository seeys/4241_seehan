# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seehan <seehan@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/16 00:15:08 by seehan            #+#    #+#              #
#    Updated: 2021/03/16 00:16:31 by seehan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

PATH_SRCS = ./srcs/

SRCS		=	./srcs/ft_putchar.c\
				./srcs/ft_putstr.c\
				./srcs/ft_strlen.c\
				./srcs/ft_strcmp.c\
				./srcs/ft_swap.c\

OBJS		=	$(SRCS:.c=.o)

INCLUDES	=	./includes/

CFLAGS		=	-Wall -Wextra -Werror

all:	$(NAME)

.c.o :
	gcc -c $(CFLAGS) -I $(INCLUDES) $< -o $(<:.c=.o)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
