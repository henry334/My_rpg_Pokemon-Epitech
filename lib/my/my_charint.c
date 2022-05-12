/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_getnbr.c
*/

#include "../../includes/print.h"

int is_int(char s)
{
    if (s < 48 || s > 57)
        return 0;
    return 1;
}

int my_charint(char *buffer)
{
    int x = my_strlen(buffer, 127);
    int neg = 0;
    int count = 0;
    buffer[0] == '-' ? x--, count = 1, neg = 1 : buffer[0];
    int x2 = x;
    neg == 1 ? x2 += 1 : x2;
    int size = 1;
    for (x; 1 < x; x--) {
        size = size * 10;
    }
    int num = 0;
    for (count; count < x2 || count == 1 && x2 == 1; count++) {
        int n = (buffer[count] - '0') * size;
        num = num + n;
        size = size / 10;
    }
    num = neg == 1 ? num * -1 : num;
    return num;
}
