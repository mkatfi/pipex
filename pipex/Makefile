NAME =  pipex

SRC = pipex.c \
		ft_split.c \
		util.c \
		open_file.c 


SRCB =  bonus/bonus.c \
		bonus/get_next_line.c\
		bonus/get_next_line_utils.c\
		bonus/main_bonus.c \
		bonus/ft_split_bonus.c \
		bonus/util_bonus.c \
		bonus/ft_putstr_fd.c 

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)


OBJB = $(SRCB:.c=.o)


all : $(NAME)

$(NAME) : $(OBJ)
	cc $(CFLAGS) $(OBJ) -o $(NAME)


bonus : $(OBJB)
	cc $(CFLAGS) $(OBJB) -o $(NAME)

clean:
	rm -f ${OBJ}
	rm -f ${OBJB}

fclean: clean
	rm -f ${NAME}

re: fclean all bonus
