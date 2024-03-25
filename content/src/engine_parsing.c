/*
** EPITECH PROJECT, 2024
** myrpg-Github
** File description:
** engine_parsing
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

//need my lib here
int my_strlen(const char *str)
{
    int len = 0;

    for (int i = 0; str[i]; i++)
        len++;
    return len;
}

//need my lib here
static int spaces_counter(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == ' ');
            nb++;
    }
    return nb;
}

//need my lib here
int is_char_printable(char str)
{
    int i = 0;

    if (str >= '!' && str <= '~')
        return 0;
    return 1;
}

//need my lib here
char **my_str_to_word_array(char *str)
{
    int x = 0;
    int y = 0;
    char **tab;

    for (; *str == ' '; str++);
    tab = malloc(sizeof(char *) * spaces_counter(str));
    for (int j = 0; j < my_strlen(str); j++) {
        tab[x] = malloc(my_strlen(str));
        y = 0;
        for (; is_char_printable(str[j]) == 0 && str[j] != ' '; j++) {
            tab[x][y] = str[j];
            y++;
        }
        tab[x][y] = '\0';
        x++;
        for (; str[j + 1] == ' '; j++);
    }
    tab[x] = NULL;
    return tab;
}

//need my lib here
int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; (s1[i] != '\0') || (s2[i] != '\0'); i++)
        if (s2[i] != s1[i])
            return (s2[i] - s1[i]);
    return (s1[i] - s2[i]);
}

//need my lib here
int my_getnbr(char const *str)
{
    int neg = 1;
    int nbr = 0;
    int i = 0;

    if (str[0] == '-'){
        neg = -1;
        i++;
    }
    for (; str[i] != '\0'; i++){
        nbr *= 10;
        nbr += (str[i] - '0');
    }
    return (nbr * neg);
}

static char *open_file(void)
{
    char *str;
    int fd = open("../engine.settings", O_RDONLY);
    char buf[2];
    int nb_c = 0;

    if (fd == -1)
        return NULL;
    for (nb_c = 0; read(fd, buf, 1) > 0; nb_c++);
    close(fd);
    str = malloc(sizeof(char) * (nb_c + 1));
    fd = open("../engine.settings", O_RDONLY);
    read(fd, str, nb_c);
    str[nb_c] = '\0';
    close(fd);
    return str;
}

char **creat_tab(char *str)
{
    int num_lines = 0;
    char **tab;
    int j = 0;
    int k = 0;

    for (int i = 0; str[i] != '\0'; i++)
        num_lines += (str[i] == '\n') ? 1 : 0;
    tab = malloc(sizeof(char *) * (num_lines + 2));
    for (int i = 0; str[i] != '\0'; j++) {
        for (; str[i] == '\n'; i++);
        tab[j] = malloc((my_strlen(str) + 1));
        for (k = 0; str[i] != '\0' && str[i] != '\n'; k++) {
            tab[j][k] = str[i];
            i++;
        }
        tab[j][k] = '\0';
    }
    tab[j] = NULL;
    return tab;
}

char *my_getname(char *str)
{
    int name_len = my_strlen(str);

    if (str[0] != '"' || str[name_len - 1] != '"'){
        write(2, "ERROR : '\"' needed before and after the name\n", 46);
        exit(84);
    }
    str[name_len - 1] = '\0';
    return &str[1];
}

int parsing(char **tab)
{
    char **word_tab = malloc(sizeof(char *) * 3);

    for (int i = 0; tab[i]; i++){
        word_tab = my_str_to_word_array(tab[i]);
        if (!my_strcmp(word_tab[0], "height"))
            printf("height_var = %d\n", my_getnbr(word_tab[1]));
        if (!my_strcmp(word_tab[0], "width"))
            printf("width_var = %d\n", my_getnbr(word_tab[1]));
        if (!my_strcmp(word_tab[0], "fps"))
            printf("fps_var = %d\n", my_getnbr(word_tab[1]));
        if (!my_strcmp(word_tab[0], "bit"))
            printf("bit_var = %d\n", my_getnbr(word_tab[1]));
        if (!my_strcmp(word_tab[0], "name"))
            printf("name_var = %s\n", my_getname(&tab[i][5]));
    }
}

int main(int ac, int av)
{
    char *data_buffer = open_file();
    char **file_data = creat_tab(data_buffer);

    parsing(file_data);
    for (int i = 0; file_data[i]; i++){
        free(file_data[i]);
    }
    free(file_data);
    free(data_buffer);
    return 0;
}

/*
you only have to :
    - change all the printfs
    - add the functions with comm in a lib (i have them in my lib, but no lib here LMAO)
    - coding style done :  remove the functions and this comm
*/
