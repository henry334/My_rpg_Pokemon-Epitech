/*
** EPITECH PROJECT, 2022
** epitech
** File description:
** code.c
*/

#include "../../includes/print.h"

int my_check(char *parse, int where, char *string)
{
    int c = 0;
    for (c; parse[c] != '\0'; c++, where++) {
        if (parse[c] != string[where])
            return -1;
    }
    return c;
}
