/*
** EPITECH PROJECT, 2021
** epitech
** File description:
** my_revstr.c
*/

int my_strsize(char const *str)
{
    int x = 0;
    while (*str != '\0' ) {
        x++;
        str++;
    }
    return x;
}

char *my_revstr(char *str)
{
    char suite;
    int y = 0;
    int v = my_strsize(str) - 1;
    while (v > y) {
        suite = str[y];
        str[y] = str[v];
        str[v] = suite;
        y = y + 1;
        v = v - 1;
    }
    return str;
}