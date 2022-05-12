/*
** EPITECH PROJECT, 2021
** epitech
** File description:
** print.h
*/

#ifndef PRINT_H_
    #define PRINT_H_
    #include <stdlib.h>

int my_put_nbr(int);
int my_strlen(char const *str, char skip);
int my_intlen(long long number, int div);
int is_int(char s);
void my_putchar(char);
int my_putstr(char const *);
void my_printf(char *, ...);
char *my_revstr(char *);
int my_twod_size(char **temp);
int my_strcomp(char *str, char *tooc);
int my_getnbr(char const *);
char *my_intchar(long long num);
int my_charint(char *buffer);
char *my_strdup(char *to_copy);
char *my_conc(char *f, char *s, char b);
char *my_simple_conc(char *f, char s, char b);
char **my_split(char *argv, char *parse, int t);
int num_args(char *argv, char *parse, int t, int c);
int my_check(char *parse, int where, char *string);
int *my_intstrip(int mode, int *buff, int size, int parse);

#endif/*PRINT_H_*/
