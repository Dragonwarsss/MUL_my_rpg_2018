##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make
##

CC	=	gcc -Iinclude

NAME	=	map_editor

SRCS	=	src/main.c		\
		src/print_help.c	\
		src/load_conf.c		\
		src/load_map.c		\
		src/get_opt.c		\
		src/init.c		\
		src/set_edit.c		\
		src/display_map.c	\
		src/move_map.c		\
		src/select_block.c	\
		src/get_pos_map.c	\
		src/put_block.c		\
		src/select_map.c	\
		src/key_map.c		\
		src/change_text.c	\
		src/action.c		\
		src/save.c		\
		src/free_everything.c	\

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra -pedantic -L../lib/my/ -lmy

all:	libs $(NAME)

libs:
	$(MAKE) -C ../lib/my/ OUTDIR=.

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS) -L../lib/pixel/ -lcsfml-window -lcsfml-graphics
clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C ../lib/my/

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C ../lib/my/

re: fclean all

.PHONY: all clean fclean re
