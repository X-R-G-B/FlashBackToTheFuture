/*
** EPITECH PROJECT, 2025
** my bgs
** File description:
** resolve_path.c
*/

#include "my_bgs.h"
#include "my_puts.h"
#include "my_strings.h"

const char *resolve_path(const char *path_root, const char *path)
{
    static char buffer[2048] = {0};

    buffer[0] = '\0';
    my_strcat(buffer, path_root);
    my_strcat(buffer, path);
    return buffer;
}
