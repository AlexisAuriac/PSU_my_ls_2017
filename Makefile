##
## EPITECH PROJECT, 2017
## my_ls
## File description:
## Makefile for my_ls.
##

SRC	=	src/main.c		\
		src/get_dirs.c		\
		src/create_entry.c	\
		src/delete.c		\
		src/show_dirs.c		\
		src/analyse_argv.c	\
		src/flag_r.c		\
		src/flag_d.c		\
		src/flag_l.c		\
		src/flag_t.c		\
		src/flag_R.c		\
		src/insert_dir_list.c

OBJ	=	$(SRC:.c=.o)

CPPFLAGS+=	-I include

CFLAGS	+=	-Wall -Wextra

LDFLAGS	=	-Llib -lmy

NAME	=	my_ls

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean	all

.PHONY	:	all lib clean fclean re
