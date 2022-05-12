/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** code.c
*/

#include "../../includes/print.h"

int my_twod_size(char **temp)
{
    int c = 0;

    while (temp[c] != NULL) {
        c++;
    }
    return c;
}