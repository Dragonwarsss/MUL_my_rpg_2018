##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make
##

CC	=	gcc -I include

NAME	=	my_rpg

SRCS	=	src/main.c				\
		src/my_puterr.c				\
		src/init.c				\
		src/load_map.c				\
		src/exec_mouse_button_scene.c		\
		src/manage_menu_input.c			\
		src/create_ll_menu.c			\
		src/change_scene.c			\
		src/select_scene.c			\
		src/display_menu.c			\
		src/display_skill_tree.c		\
		src/display_map.c			\

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra -pedantic -lcsfml-graphics

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	find . -path "./*" -name "*.gcno" -type f -delete -o -name "*.gcda" -delete

re: fclean all

tests_run:
	$(MAKE) -C unit_tests/
	cd unit_tests && ./test
	gcovr

init:
	@git remote set-url --add --push origin git@git.epitech.eu:/paul.naudin@epitech.eu/MUL_my_rpg_2018
	@git remote set-url --add --push origin git@github.com:Dragonwarsss/MUL_my_rpg_2018

.PHONY: all clean fclean re tests_run
