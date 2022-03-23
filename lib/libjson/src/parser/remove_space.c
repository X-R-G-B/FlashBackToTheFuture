/*
** EPITECH PROJECT, 2022
** json parser
** File description:
** remove space
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "my_puts.h"

bool is_nb(char c)
{
    if ((c >= 48 && c <= 57) || c == '-') {
        return true;
    } else {
        return false;
    }
}

static void add_to_counter(int *ch_nb, char const *str, int i, bool is_in_str)
{
    if (is_nb(str[i]) == true && (is_nb(str[i - 1]) == false &&
        str[i - 1] != '.') && is_in_str == false) {
        *ch_nb = *ch_nb + 1;
    }
    if (i > 0 && is_nb(str[i]) == false && str[i] != '.' &&
        is_nb(str[i - 1]) == true && str[i] != 34 && is_in_str == false) {
        *ch_nb = *ch_nb + 1;
    }
    if ((str[i] != ' ' || is_in_str == true) && str[i] != '\n') {
        *ch_nb = *ch_nb + 1;
    }
}

static int get_char_nb(char const *str, bool is_in_str)
{
    int ch_nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 34) {
            is_in_str = (is_in_str == true) ? false : true;
        }
        add_to_counter(&ch_nb, str, i, is_in_str);
    }
    return ch_nb;
}

static void check_char(char const *str, int i[], bool is_in_str, char *new)
{
    static int fill_new = 0;

    if (is_nb(str[i[0]]) == true && (is_nb(str[i[0] - 1]) == false &&
        str[i[0] - 1] != '.') && is_in_str == false) {
        fill_new += 1;
        new[i[1]] = 21;
        i[1] = i[1] + 1;
    }
    if (i[1] > 0 && is_nb(str[i[0]]) == false && str[i[0]] != '.' &&
        is_nb(new[i[1] - 1]) == true && str[i[0]] != 34 && is_in_str == false) {
        fill_new += 1;
        new[i[1]] = 21;
        i[1] = i[1] + 1;
    }
    if ((str[i[0]] != ' ' || is_in_str == true) && str[i[0]] != '\n') {
        fill_new += 1;
        new[i[1]] = str[i[0]];
        i[1] = i[1] + 1;
    }
}

char *rm_space(char const *str)
{
    int char_nb = 0;
    char *new = NULL;
    int i[2] = {0, 0};
    bool is_in_str = false;

    if (str == NULL) {
        return NULL;
    }
    char_nb = get_char_nb(str, is_in_str);
    new = malloc(sizeof(char) * (char_nb + 1));
    if (new != NULL) {
        new[char_nb] = '\0';
    }
    for (; new != NULL && str[i[0]] != '\0'; i[0] = i[0] + 1) {
        if (str[i[0]] == 34) {
            is_in_str = (is_in_str == true) ? false : true;
        }
        check_char(str, i, is_in_str, new);
    }
    return new;
}
