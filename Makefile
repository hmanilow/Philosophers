
NAME = philosophers

FLAGS	= -Wall -Werror -Wextra -fsanitize=address

HEAD = philosophers.h

SRC = main.c \
	  parsing.c \
	  utilities.c \
	  initialization.c \
	  looking_for_the_death.c \
	  what_do_phil_do.c

OBJ		= 	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc  $(FLAGS) $(SRC) -o $(NAME)

%.o : %.c
	gcc $(FLAGS) -c $<

clean:
	/bin/rm -f $(OBJ)
	make -C clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C  fclean

re: fclean all