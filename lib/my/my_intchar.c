/*
** EPITECH PROJECT, 2022
** epitech
** File description:
** code.c
*/

#include "../../includes/print.h"

char *my_intchar(long long num)
{
    int new = 0;
    int counter = 0;
    int neg = 1;
    num < 0 ? num = num * -1, neg++ : counter;
    char *list = malloc(sizeof(char) * (my_intlen(num, 10) + neg + 1));
    if (num <= 9) {
        list[counter] = num + '0';
        neg == 2 ? counter++, list[counter] = '-' : neg;
        list[counter + 1] = '\0';
    } else {
        for (counter; num > 0; counter++) {
            new = num % 10;
            num = num / 10;
            list[counter] = new + '0';
        }
        neg == 2 ? neg, list[counter] = '-', counter++ : neg;
        list[counter] = '\0';
    }
    return my_revstr(list);
}
