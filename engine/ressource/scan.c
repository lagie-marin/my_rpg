/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** scan.c
*/
#include "engine/core.h"
#include "engine/ressource.h"
#include "engine/window.h"

static maps_t *create_map(char *name, char *path)
{
    maps_t *newNode = malloc(sizeof(maps_t));
    array name_extension = my_strtok(name, '.');

    my_strcpy(newNode->name, name_extension[0]);
    my_strcpy(newNode->path, path);
    newNode->next = NULL;
    free_strarray(name_extension);
    return newNode;
}

static void append_map(maps_t **head_ref, char *name, char *path)
{
    maps_t *newNode = create_map(name, path);
    maps_t *last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
}

static void process_directory_entry(char *path, char *filename, maps_t **head)
{
    struct stat buf;
    char *extension;

    if (stat(path, &buf) == 0 && S_ISDIR(buf.st_mode))
        scan(path);
    else {
        extension = my_strchr(filename, '.');
        if (extension != NULL && !my_strcmp(extension, ".gmap"))
            append_map(head, filename, path);
    }
}

void delete_scan(void)
{
    maps_t *current = get_mapinfo()->maps;
    maps_t *next;

    while (current != NULL) {
        next = current->next;
        FREE(current);
        current = next;
    }
}

maps_t *scan(char *basePath)
{
    char path[1000];
    struct dirent *d;
    DIR *dir = opendir(basePath);
    maps_t *head = NULL;

    if (dir == NULL && put_error("Folder does not exist!"))
        return NULL;
    d = readdir(dir);
    while (d != NULL) {
        if (my_strcmp(d->d_name, ".") && my_strcmp(d->d_name, "..")) {
            my_strcpy(path, basePath);
            my_strcat(path, "/");
            my_strcat(path, d->d_name);
            process_directory_entry(path, d->d_name, &head);
        }
        d = readdir(dir);
    }
    closedir(dir);
    return head;
}
