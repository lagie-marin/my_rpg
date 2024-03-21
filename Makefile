##
## EPITECH PROJECT, 2024
## B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
## File description:
## Makefile
##
SRC = ./content/src/my_paint.c \
	./engine/core/file/my_getline.c \
	./engine/core/numbers/my_intlen.c \
	./engine/core/numbers/my_strtof.c \
	./engine/core/numbers/my_strtol.c \
	./engine/core/puts/my_printf.c \
	./engine/core/puts/my_put_nbr.c \
	./engine/core/puts/my_putchar.c \
	./engine/core/puts/my_putstr.c \
	./engine/core/puts/put_error.c \
	./engine/core/string/array/my_str_to_word_array.c \
	./engine/core/string/array/str_arraylen.c \
	./engine/core/string/free/free_strarray.c \
	./engine/core/string/free/free_strnarray.c \
	./engine/core/string/my_atoi.c \
	./engine/core/string/my_isspace.c \
	./engine/core/string/my_memset.c \
	./engine/core/string/my_strcat.c \
	./engine/core/string/my_strchr.c \
	./engine/core/string/my_strcmp.c \
	./engine/core/string/my_strcpy.c \
	./engine/core/string/my_strdup.c \
	./engine/core/string/my_strlen.c \
	./engine/core/string/my_strtok.c \
	./engine/core/string/nb_leading_space.c \
	./engine/core/string/str.c \
	./engine/core/string/letters.c \
	./engine/ressource/texture/texture.c \
	./engine/ressource/texture/gettexture.c \
	./engine/ressource/texture/settexture.c \
	./engine/ressource/widgets/canvas/setcanvas.c \
	./engine/ressource/widgets/canvas/step.c \
	./engine/ressource/widgets/canvas/unload_canvas.c \
	./engine/ressource/widgets/canvas/parse_canvas.c \
	./engine/ressource/widgets/canvas/getcanvas.c \
	./engine/ressource/widgets/combo/combo.c \
	./engine/ressource/widgets/combo/setcombos.c \
	./engine/ressource/widgets/widget.c \
	./engine/ressource/load.c \
	./engine/ressource/scan.c \
	./engine/system/events/init_events.c \
	./engine/system/events/register_event.c \
	./engine/system/ui/current_canvas.c \
	./engine/system/ui/map_info.c \
	./engine/system/window.c \
	./engine/system/event_manager.c \
	./engine/system/game_loop.c \

OBJ = ${SRC:.c=.o}
CFLAGS = -Werror -Wall -Wextra -Iinclude -g3
LIBS = -lcsfml-graphics -lcsfml-system -lcsfml-window -lm
NAME = my_rpg
all: $(NAME)

$(NAME): $(OBJ)
	gcc ${OBJ} -o ${NAME} ${LIBS}

clean:
	rm -f ${OBJ}
	rm -f sandbox-gmon*
	rm -f *.gcda
	rm -f *.gcno
	rm -f unit_test
	rm -f gmon.out
	rm -f *~
	rm -f .#*
	rm -f \#*
	rm -f vgcore.*

fclean: clean
	rm -f ${NAME}
re: fclean all
