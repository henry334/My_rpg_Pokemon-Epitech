/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** my_putstr.c
*/

#include "../../includes/print.h"

int my_putstr(char const *str)
{
    int x = 0;
    while (str[x] != '\0' ) {
        my_putchar(str[x]);
        x++;
    }
    return 0;
}
