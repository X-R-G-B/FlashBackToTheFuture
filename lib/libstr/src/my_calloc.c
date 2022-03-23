/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** malloc and set all to \0
*/

#include <stdlib.h>

/**
** @brief malloc n block and fill it with \0
** @param n
** @return null if cannot malloc; the new char * otherwise
**/
char *my_calloc(int n)
{
    char *new = malloc(sizeof(char) * n);

    if (new == NULL) {
        return (NULL);
    }
    for (int i = 0; i < n; i++) {
        new[i] = '\0';
    }
    return (new);
}
