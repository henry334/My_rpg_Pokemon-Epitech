/*
** EPITECH PROJECT, 2022
** epitech
** File description:
** code.c
*/

#include "../../includes/print.h"

int num_args(char *argv, char *parse, int t, int c)
{
    int num = 0;
    int lock;

    for (c; argv[c] != '\0'; c++) {
        lock = my_check(parse, c, argv);
        lock != -1 ? t-- : t;
        if (t < 0 && lock != -1) {
            num++;
            c = lock + c - 1;
        }
    }
    return num;
}
