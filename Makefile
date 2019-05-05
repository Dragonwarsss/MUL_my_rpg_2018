##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make
##

CFLAGS	=	-Wall -Wextra -pedantic

LDFLAGS =	-lcsfml-graphics -lcsfml-audio -lcsfml-system

DEBUG	?= 0

ifeq ($(DEBUG), 1)
	CFLAGS += -g3
endif

CC	=	gcc -I include

NAME	=	my_rpg

SRCS	=	src/main.c				\
		src/my_puterr.c				\
		src/characters/create_ll_char.c		\
		src/initialization/init.c		\
		src/initialization/load_map.c		\
		src/initialization/create_ll_menu.c	\
		src/initialization/create_ll_ennemies.c	\
		src/initialization/init_player.c	\
		src/initialization/init_music.c		\
		src/initialization/init_text.c		\
		src/initialization/init_utils.c		\
		src/initialization/init_timer.c		\
		src/initialization/init_invader.c	\
		src/initialization/create_ll_text_end.c	\
		src/initialization/create_ll_text_restart.c	\
		src/exec_mouse_button_scene.c		\
		src/input/check_key_press_scene.c	\
		src/input/manage_menu_input.c		\
		src/change_scene.c			\
		src/select_scene.c			\
		src/display/draw_scene.c		\
		src/display/display_option.c		\
		src/display/display_map.c		\
		src/display/display_menu.c		\
		src/display/display_skill_tree.c	\
		src/display/display_game.c		\
		src/display/display_player.c		\
		src/display/display_text.c		\
		src/display/display_invader.c		\
		src/display/display_ennemies.c		\
		src/initialization/create_ll_options.c	\
		src/opt_music.c				\
		src/input/check_key_move.c		\
		src/collides/collide.c			\
		src/input/move_map.c			\
		src/display/display_pause.c		\
		src/initialization/create_ll_pause.c	\
		src/collides/interact.c			\
		src/input/check_enter_key.c		\
		src/utils/my_strncpy.c			\
		src/utils/my_strlen.c			\
		src/utils/my_putstr.c			\
		src/timer/start_clock.c			\
		src/input/check_key_invader.c		\
		src/event/project_end.c			\


OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS)
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
