/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** core.h
*/

#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>

#ifndef CORE_H
    #define CORE_H
    #define LEN(str) my_strlen(str)
    #define FREE(str) if (str != NULL) free(str)
    #define IS_CARACT(ch) (ch >= '!' && ch <= '~' && ch != ' ')
    #define IS_DIGIT(ch) (ch >= '0' && ch <= '9')
    #define RETURN_IF(condition, output) if (condition) return (output)
    #define IS_ON_MAP(s) (s == ON_MAP)
    #define ICON "../../engine/assets/img/grap"
typedef const char cc;
typedef enum status_e status;
typedef char **array;

enum status_e {
    FAIL,
    SUCCESS
};

/*file function*/
ssize_t my_getline(array input, size_t *len, FILE *stream);

/*number function*/
int my_intlen(int value);
double my_strtof(char *str);
long int my_strtol(char *string, array end);

/*put function*/
int my_printf(const char *format, ...);
int my_put_nbr(int n);
void my_putchar(char c);
int my_putstr(const char *str);
int put_error(char *str);

/*char *function*/
array my_str_to_word_array(const char *str);
int str_arraylen(array src);
int free_strarray(array arr);
int free_strnarray(array arr, int pos);
int my_isspace(char arg);
char *my_memset(char *str, char ch, int length);
char *my_strcat(char *dest, char const *src);
char *my_strchr(char *str, char ch);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(const char *str);
array my_strtok(const char *str, cc delimiters);
char *my_strdup(char const *src);
int my_atoi(char const *str);
int nb_leading_space(char *str);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char *str);
int my_str_isprintable(char *str);
int my_str_isupper(char *str);
int my_isletter_islow(char args);
int my_isletter_isupper(char args);
int my_isletter(char args);
int my_isnum(char i);
int is_alphanumeric(char args);
#endif
