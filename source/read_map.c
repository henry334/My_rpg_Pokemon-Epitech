/*
** EPITECH PROJECT, 2022
** read_file
** File description:
** file
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

char *readfile(char *path)
{
    int rt;
    int file;
    struct stat size_buf;
    stat(path, &size_buf);
    file = open(path, O_RDONLY);
    if (file == -1)
        return "error";
    char *buffer = malloc(size_buf.st_size + 3);
    rt = read(file, buffer, size_buf.st_size);
    if (rt == -1) {
        free(buffer);
        return "error";
    }
    buffer[rt] = '\0';
    return buffer;
}