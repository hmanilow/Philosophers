NAME	=	philo_bonus

FLAGS	=	-Wall -Werror -Wextra -pthread

HEAD	=	philo_bonus.h

SRC 	=	philo_bonus.c \
			parsing_bonus.c \
	  		utilities_bonus.c \
	  		initialization_bonus.c \
	  		looking_for_the_d_bon.c \
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