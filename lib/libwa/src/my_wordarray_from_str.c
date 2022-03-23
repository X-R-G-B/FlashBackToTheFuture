/*
** EPITECH PROJECT, 2022
** LIBMY
** File description:
** str to word array
*/

#include <stdlib.h>

static int get_array_size(const char *str, char delim)
{
    int size = 0;
    int i = 1;

    if (str == NULL || str[0] == '\0') {
        return (size);
    }
    for (; str[i] != '\0'; i++) {
        if (str[i] == delim && str[i - 1] != delim) {
            size++;
        }
    }
    if (str[i - 1] != delim) {
        size++;
    }
    return (size);
}

static char *cut_word_before(const char *str, int i, char delim)
{
    int index_start = i - 1;
    char *new;

    for (; index_start > 0 && str[index_start] != delim; index_start--);
    if (index_start != 0) {
        index_start++;
    }
    new = malloc(sizeof(char) * (i - index_start + 1));
    for (int j = index_start; new != NULL && j < i; j++) {
        new[j - index_start] = str[j];
    }
    new[i - index_start] = '\0';
    return (new);
}

static char **fill_word_array(const char *str, int array_size, char **array,
        char delim)
{
    int index = 0;
    int i = 1;
    int is_error = 0;

    for (; str[i] != '\0' && index < array_size && is_error == 0; i++) {
        if (str[i] == delim && str[i - 1] != delim) {
            array[index++] = cut_word_before(str, i, delim);
        }
        if (index != 0 && array[index - 1] == NULL) {
            is_error = 1;
        }
    }
    if (is_error) {
        return (NULL);
    }
    if (str[i - 1] != delim) {
        array[index] = cut_word_before(str, i, delim);
    }
    return (array);
}

/**
** @brief put each "word" defining by delimiters in a 2d array
** @param str
** @param delim
** @return null if any error occurs; else the 2d array
**/
char **my_wordarray_from_str(const char *str, char delim)
{
    char **array;
    int array_size = get_array_size(str, delim);

    if (array_size == 0) {
        return (NULL);
    }
    array = malloc(sizeof(char *) * (array_size + 1));
    if (array == NULL) {
        return (NULL);
    }
    array = fill_word_array(str, array_size, array, delim);
    if (array != NULL) {
        array[array_size] = NULL;
    }
    return (array);
}
