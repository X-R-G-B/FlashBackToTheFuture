/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** create collison map
*/

#include <stdlib.h>
#include "my_wordarray.h"
#include "my_strings.h"

static char **fill_array(char **new, int arr_len, int str_len)
{
    for (int i = 0; i < arr_len; i++) {
        new[i] = malloc(sizeof(char) * (str_len + 1));
        if (new[i] == NULL) {
            return NULL;
        }
        new[i][str_len] = '\0';
        for (int x = 0; x < str_len; x++) {
            new[i][x] = '#';
        }
    }
    return new;
}

char **create_new_map(char **map)
{
    int arr_len = my_wordarray_len(map);
    int str_len = my_strlen(map[0]);
    char **new = malloc(sizeof(char *) * (arr_len + 1));
    int current_len = 0;

    if (new == NULL) {
        return NULL;
    }
    new[arr_len] = NULL;
    for (int i = 0; i < arr_len; i++) {
        current_len = my_strlen(map[i]);
        str_len = (current_len > str_len) ? current_len : str_len;
    }
    return fill_array(new, arr_len, str_len);
}

