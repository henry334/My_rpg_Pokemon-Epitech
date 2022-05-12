/*
** EPITECH PROJECT, 2021
** Epitech
** File description:
** my_printf.c
*/

#include <stdarg.h>
#include <stdio.h>
#include "../../includes/print.h"

void types2(int counter, char *s, va_list list)
{
    char tp2 = s[counter + 1];
    switch (tp2) {
        case 's':
        my_putstr(va_arg(list, void *));
        break;
        case '%':
        my_putchar('%');
        break;
    }
}

void types(int counter, char *s, va_list list)
{
    char tp = s[counter + 1];
    switch (tp) {
        case 'c':
        my_putchar(va_arg(list, int));
        break;
        case 'i':
        my_put_nbr(va_arg(list, int));
        break;
        case 'd':
        my_put_nbr(va_arg(list, int));
        break;
        default:
        types2(counter, s, list);
        break;
    }
}

void my_printf(char *s, ...)
{
    va_list list;
    va_start(list, s);
    int counter = 0;
    for (counter; s[counter] != '\0' ; counter++) {
        if (s[counter] == '%') {
            types(counter, s, list);
            counter++;
        } else {
            my_putchar(s[counter]);
        }
    }
    va_end(list);
}
