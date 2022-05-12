/*
** EPITECH PROJECT, 2021
** epitech
** File description:
** the_code
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

int check_size(char *string, char *parse, int size)
{
    int l;
    char **temp;

    temp = my_split(string, parse, 0);
    l = my_twod_size(temp);
    if (l != size)
        return 1;
    free_double_char(temp);
    return 0;
}