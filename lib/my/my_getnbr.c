/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_getnbr.c
*/

#include "../../includes/print.h"

int isneg(int nbr, int neg)
{
    if (neg % 2 == 0)
        return nbr;
    else
        return nbr * (-1);
}

int my_getnbr(char const *str)
{
    int len = my_strlen(str, 127);
    int neg = 0;
    long nbr = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] >= 48 && str[i] < 48 + 10) {
            nbr = nbr * 10 + ((int) str[i] - 48);
        } else {
            nbr = isneg(nbr, neg);
            return -1;
        }
    }
    nbr = isneg(nbr, neg);
    return nbr;
}