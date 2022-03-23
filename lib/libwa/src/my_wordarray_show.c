/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** show word array with \n between
*/

#include <stddef.h>
#include <stdio.h>
#include "my_puts.h"
#include "my_strings.h"

/**
** @brief print each char * of the 2d array with a newline after each char *
** @param array
**/
void my_wordarray_showln(char *const *array)
{
    if (array == NULL) {
        return;
    }
    for (int i = 0; array[i] != NULL; i++) {
        my_putstr(1, array[i]);
        my_putchar(1, '\n');
    }
}

/**
** @brief print each char * of the 2d array
** @param array
**/
void my_wordarray_show(char *const *array)
{
    if (array == NULL) {
        return;
    }
    for (int i = 0; array[i] != NULL; i++) {
        my_putstr(1, array[i]);
    }
}

void my_wordarray_write(char *const *array, char const *path)
{
    FILE *file = NULL;

    if (array == NULL) {
        return;
    }
    file = fopen(path, "w");
    if (file == NULL) {
        return;
    }
    for (int i = 0; array[i] != NULL; i++) {
        fwrite(array[i], sizeof(char), my_strlen(array[i]), file);
        fwrite("\n", sizeof(char), 1, file);
    }
    fclose(file);
}
