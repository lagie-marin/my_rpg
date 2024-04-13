/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** load.c
*/
#include "engine/core.h"
#include "engine/ressource.h"
#include "engine/window.h"

static void clean_load(char *line, canvas_t **step)
{
    FREE(line);
    FREE(step);
}

static status_t is_widget(char *str, char *to_find, gbool_t is_map)
{
    int x = 0;

    for (int i = 0; to_find[i]; i++) {
        for (; is_map == TRUE && my_isspace(str[x]); x++);
        if (str[x + i] != to_find[i])
            return FAIL;
    }
    return SUCCESS;
}

static sload_t gmap_parser(char *line, char *name, canvas_t ***step, sload_t s)
{
    if (is_widget(line, "TEXTURE", FALSE))
        return gmap_parse_texture(line);
    if (is_widget(&line[1], name, FALSE) && line[LEN(name) + 1] == ']')
        return ON_MAP;
    if (is_widget(line, "[CANVAS;", IS_ON_MAP(s)))
        return gmap_parse_canvas(line, step, s);
    if (is_widget(line, "BUTTON", TRUE))
        return gmap_parse_button(line, *step, s);
    if (is_widget(line, "[END]", TRUE)) {
        *step = rm_step(*step);
        return OUT_MAP;
    }
    return s;
}

static maps_t *get_current_map(char *name)
{
    maps_t *current_maps = get_mapinfo()->maps;

    while (current_maps != NULL && my_strcmp(current_maps->name, name))
        current_maps = current_maps->next;
    return current_maps;
}

static canvas_t **stepac(void)
{
    canvas_t **step = malloc(sizeof(canvas_t *));

    step[0] = NULL;
    return step;
}

static FILE *check_validation_info(char *name, maps_t *current_maps)
{
    FILE *file;

    if (current_maps == NULL && put_error(name) && put_error(MAP_NOT_EXIST))
        return NULL;
    file = fopen(current_maps->path, "r");
    if (file == NULL && put_error(FD_NOT_EXIST))
        return NULL;
    return file;
}

status_t load_map(char *name)
{
    FILE *file;
    maps_t *current_maps = get_current_map(name);
    char *line = NULL;
    size_t len;
    ssize_t read;
    canvas_t **step = stepac();
    sload_t s = NONE;

    file = check_validation_info(name, current_maps);
    if (file == NULL)
        return FAIL;
    read = my_getline(&line, &len, file);
    while (read != -1 && my_strcmp(line, "[END-MAP]") && s != ERROR) {
        s = gmap_parser(line, name, &step, s);
        read = my_getline(&line, &len, file);
    }
    fclose(file);
    clean_load(line, step);
    RETURN_IF(s != ERROR, SUCCESS);
    return FAIL;
}
