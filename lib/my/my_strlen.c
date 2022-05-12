/*
** EPITECH PROJECT, 2021
** epitech
** File description:
** my_strlen.c
*/

int my_strlen(char const *str, char skip)
{
    int x = 0;
    while (str[x] != '\0') {
        if (str[x] != skip || skip == 127)
            x++;
    }
    return x;
}

int my_intlen(long long number, int div)
{
    int count = 0;
    for (number; number > 0; number = number / div) {
        count++;
    }
    return count;
}
