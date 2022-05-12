/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** code.c
*/

#include "../../includes/print.h"

int my_strcomp(char *str, char *tooc)
{
    if (my_strlen(str, 127) != my_strlen(tooc, 127))
        return 0;
    for (int c = 0; str[c] != '\0'; c++) {
        if (str[c] == tooc[c]) {
        } else
            return 0;
    }
    return 1;
}
