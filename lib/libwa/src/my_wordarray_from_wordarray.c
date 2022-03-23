/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** copy a word array
*/

#include <stdlib.h>
#include "my_strings.h"
#include "my_wordarray.h"

/**
** @brief copy a null terminated 2d array null terminated 1d array
** @param env[]
** @return null if lenght of env is 0 or cant malloc; else the new 2d array
**/
char **my_wordarray_from_wordarray(char *const env[])
{
    int len = my_wordarray_len(env);
    char **new;

    if (len == 0) {
        return (NULL);
    }
    new = malloc(sizeof(char *) * (len + 1));
    if (new == NULL) {
        return (NULL);
    }
    for (int i = 0; env[i] != NULL; i++) {
        new[i] = my_strdup(env[i]);
    }
    new[len] = NULL;
    return (new);
}
