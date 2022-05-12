/*
** EPITECH PROJECT, 2022
** epitech
** File description:
** code.c
*/

#include "../../includes/print.h"

char *my_strdup(char *to_copy)
{
    int c = 0;
    char *new = malloc(sizeof(char) * (my_strlen(to_copy, 127) + 1));
    for (c; to_copy[c] != '\0'; c++) {
        new[c] = to_copy[c];
    }
    new[c] = '\0';
    return new;
}
