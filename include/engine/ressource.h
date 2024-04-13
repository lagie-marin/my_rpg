/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** ressource.h
*/
#include "core.h"

#ifndef RESSOURCE_H
    #define RESSOURCE_H
    #define MAP_NOT_EXIST " map is not exist\n"
    #define FD_NOT_EXIST "No such file or directory\n"
typedef enum sload_e sload_t;
typedef struct maps_s maps_t;

enum sload_e {
    NONE,
    ON_MAP,
    OUT_MAP,
    ERROR
};

struct maps_s {
    char name[256];
    char path[1000];
    maps_t *next;
};
sfColor color(int r, int g, int b, int a);
maps_t *scan(char *basePath);
void delete_scan(void);
status_t load_map(char *map_name);

sload_t gmap_parse_texture(char *line);
#endif
