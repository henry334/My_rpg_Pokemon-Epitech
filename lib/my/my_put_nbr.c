/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** my_swap.c
*/

#include "../../includes/print.h"

int my_put_nbr(int nb)
{
    if (0 > nb) {
        if (nb == -2147483648) {
            my_putchar('-');
            my_putchar('2');
            nb = -147483648;
            nb = nb * -1;
        } else {
            my_putchar('-');
            nb = nb * -1;
        }
    }
    if (10 <= nb) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
        return (0);
    } else {
        my_putchar(nb + 48);
        return (0);
    }
}
