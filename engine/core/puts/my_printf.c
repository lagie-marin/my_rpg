/*
** EPITECH PROJECT, 2023
** B-CPE-101-LYN-1-1-myprintf-alexis.drago-beltran
** File description:
** my_printf.c
*/
#include "engine/core.h"

static void print(char c, va_list ap)
{
    if (c == 'c')
        my_putchar((int)va_arg(ap, int));
    if (c == 's')
        my_putstr(va_arg(ap, char *));
    if (c == '%')
        my_putchar('%');
    if (c == 'd' || c == 'i')
        my_put_nbr((int)va_arg(ap, int));
}

int my_printf(const char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    for (int i = 0; format[i]; i++) {
        if (format[i] == '%') {
            i++;
            print(format[i], ap);
        } else
            my_putchar(format[i]);
    }
    va_end(ap);
    return 0;
}
