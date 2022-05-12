##
## EPITECH PROJECT, 2021
## make
## File description:
## make
##

SRC		=	source/usage.c \
			my_rpg.c \
			source/manual.c \
			source/other_free.c \
			source/error_handling.c \
			source/creat_object.c \
			source/creat_square.c \
			source/creat_text.c \
			source/free.c \
			source/save_load_page.c \
			source/free_sec.c \
			source/creat_text_two.c \
			source/display.c \
			source/play.c \
			source/shop.c \
			source/inventory.c \
			source/choose_poke.c \
			source/stuff_and_arn.c \
			source/pokemon_inventory.c \
			source/creat_object_two.c \
			source/creat_object_fr.c \
			source/creat_object_tree.c \
			source/player_stuff.c \
			source/pharmacy.c \
			source/setting.c \
			source/menu.c \
			source/destroy.c \
			source/analyse_env.c \
			source/moove.c \
			source/moove_two.c \
			source/load_config.c \
			source/save.c \
			source/fight.c \
			source/pause.c \
			source/read_map.c \
			source/intro.c \
			source/setting_stuff.c \
			source/create_tuto.c \
			source/tuto.c \
			source/mooove.c \
			source/move_pause.c \
			source/pokemon_display.c \
			source/frame_loader.c \
			source/small_game_stuff.c \
			source/create_fight.c \
			source/pokemon_array_moove.c \
			source/main_fight.c \
			source/do_we_fight.c \
			source/attack.c \
			source/arceus.c \
			source/quest_menu.c \
			source/move_pause_2.c \
			source/struct.c \
			source/type_of_attack.c \
			source/particules.c

LIB		=	lib/my/my_concate.c \
			lib/my/my_getnbr.c \
			lib/my/my_strdup.c \
			lib/my/my_intchar.c \
			lib/my/my_twod_size.c \
			lib/my/my_str_comp.c \
			lib/my/my_putchar.c \
			lib/my/my_charint.c \
			lib/my/my_numarg.c \
			lib/my/my_split.c \
			lib/my/my_checker.c \
			lib/my/my_put_nbr.c \
			source/colision.c \
			lib/my/my_putstr.c \
			lib/my/my_printf.c \
			lib/my/my_revstr.c \
			lib/my/my_strlen.c

OBJ	=	$(SRC:.c=.o)

N	=	my_rpg

NAMELIB =	libmy.a

all: libmy $(OBJ)
	gcc -g -o $(N) $(OBJ) -l csfml-graphics \
	-l csfml-system -l csfml-audio -l csfml-window -L ./lib/my -lmy -lm
	make clean

libmy:
	gcc -g -c $(LIB)
	ar rc ./lib/my/$(NAMELIB) *.o
	cd lib/my && rm -f *.o

clean:
	rm -f lib/my/*.o
	rm -f vgcore*
	rm -f *~
	rm -f *.o
	cd source && rm -f *.o

fclean:	clean
	rm -f $(N)

re:	fclean all

.PHONY: clean fclean compile libmy add
