/*
** EPITECH PROJECT, 2022
** str_to_word_array
** File description:
** string to array
*/

#include <stdlib.h>
#include "list.h"

int my_strlen(char const *str);

char *cut_str(char *str, int fst, int scd)
{
    int part_len = scd - fst;
    char *str_part = malloc(sizeof(char) * (part_len + 1));
    int i = 0;

    if (!str_part)
        return NULL;
    for (; i < part_len; i++)
        str_part[i] = str[i + fst];
    str_part[part_len] = '\0';
    return str_part;
}

int add_word(int i, int *pos, char *str, list_ptr_t *list)
{
    char *str_part = NULL;

    str_part = cut_str(str, *pos, i);
    if (!str_part)
        return 84;
    list_add_to_end(list, str_part);
    *pos = i + 1;
    while (str[*pos] == ' ')
        *pos = *pos + 1;
    return 0;
}

int last_word_gestion(char *str, list_ptr_t *list, int pos, int i)
{
    int strlen = my_strlen(str);

    if (strlen < 2 && str[0] == 10)
        return 0;
    if ((str[strlen - 1] == 10 && str[strlen - 2] == ' ') ||
        str[strlen - 1] == ' ')
        return 0;
    if (str[strlen - 1] == 10 && add_word(i - 1, &pos, str, list) == 84)
        return 84;
    else if (str[strlen - 1] != 10 && add_word(i, &pos, str, list) == 84)
        return 84;
    return 0;
}

list_ptr_t *str_to_word_list(char *str)
{
    int pos = 0;
    int strlen = 0;
    int i = 1;
    list_ptr_t *list = list_create();

    if (!str || !list)
        return NULL;
    strlen = my_strlen(str);
    if (strlen == 0)
        return NULL;
    for (; i < strlen; i++)
        if (str[i] == ' ' && str[i - 1] != ' ' &&
            (pos == 0 || str[pos - 1] == ' ') && pos < i &&
            add_word(i, &pos, str, list) == 84)
            return NULL;
    if (last_word_gestion(str, list, pos, i) == 84)
        return NULL;
    return list;
}
