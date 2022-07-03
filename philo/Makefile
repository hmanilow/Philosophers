# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmanilow <hmanilow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 16:08:39 by hmanilow          #+#    #+#              #
#    Updated: 2022/05/23 16:19:52 by hmanilow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

FLAGS	=	-Wall -Werror -Wextra -pthread

HEAD	=	philosophers.h

SRCS 	=	philo.c \
			parsing.c \
	  		utilities.c \
	  		initialization.c \
	  		looking_for_the_death.c \
	  		what_do_phil_do.c

OBJS		=	${SRCS:.c=.o}

CC			=	gcc

RM			=	rm -f

all:		$(HEAD) $(NAME)

$(NAME):	$(OBJS) $(HEAD)
				$(CC) ${OBJS} -o ${NAME} ${FLAGS}

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re