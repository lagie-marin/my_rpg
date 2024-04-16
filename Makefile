##
## EPITECH PROJECT, 2024
## my_rpg
## File description:
## Makefile
##
SRC = ./content/src/tanker_than_you.c \
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
	./engine/ressource/texture/settexture.c \
	./engine/ressource/texture/texture.c \
	./engine/ressource/texture/gettexture.c \
	./engine/ressource/texture/color.c \
	./engine/ressource/texture/init_texture.c \
	./engine/ressource/widgets/canvas/step.c \
	./engine/ressource/widgets/canvas/get_canvas.c \
	./engine/ressource/widgets/canvas/set_canvas.c \
	./engine/ressource/widgets/canvas/create_canvas.c \
	./engine/ressource/widgets/canvas/canvas_utils.c \
	./engine/ressource/widgets/canvas/parse_canvas.c \
	./engine/ressource/widgets/combo/setcombos.c \
	./engine/ressource/widgets/widget.c \
	./engine/ressource/widgets/button/parse_button.c \
	./engine/ressource/widgets/button/setbtn_shape.c \
	./engine/ressource/widgets/button/setbutton.c \
	./engine/ressource/widgets/button/create_button.c \
	./engine/ressource/widgets/button/button_utils.c \
	./engine/ressource/widgets/button/get_button.c \
	./engine/ressource/widgets/manager.c \
	./engine/ressource/load.c \
	./engine/ressource/scan.c \
	./engine/system/events/default/event_button.c \
	./engine/system/events/evt_closed.c \
	./engine/system/events/evt_mouse_btn_pressed.c \
	./engine/system/events/evt_mouse_btn_released.c \
	./engine/system/events/evt_mouse_moved.c \
	./engine/system/events/get_events.c \
	./engine/system/ui/current_canvas.c \
	./engine/system/ui/map_info.c \
	./engine/system/ui/get_window.c \
	./engine/system/game_loop.c \
	./engine/system/update_window.c \
	./engine/system/event_manager.c \
	./engine/system/window.c \

OBJ = ${SRC:.c=.o}
CFLAGS = -g3 -Wall -Wextra -Iinclude
LIBS = -lcsfml-graphics \
	-lcsfml-system \
	-lcsfml-window \
	-lm
NAME = my_rpg
all: $(NAME)

$(NAME): $(OBJ)
	gcc ${OBJ} -o ${NAME} ${LIBS}

clean:
	rm -f ${OBJ}
	rm -f vgcore.*
fclean: clean
	rm -f ${NAME}
tests_run:
	echo "ok"
re: fclean all