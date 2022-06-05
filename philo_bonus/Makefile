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

NAME	=	philo_bonus

FLAGS	=	-Wall -Werror -Wextra -pthread

HEAD	=	philosophers.h

SRC 	=	philo_bonus.c \
			parsing_bonus.c \
	  		utilities_bonus.c \
	  		initialization_bonus.c \
	  		looking_for_the_death_bonus.c \
	  		what_do_phil_do_bonus.c

OBJS		=	${SRC:.c=.o}

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