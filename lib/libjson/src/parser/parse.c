/*
** EPITECH PROJECT, 2022
** libjson
** File description:
** parse
*/

#include <stdlib.h>
#include "my_strings.h"
#include "my_bgs.h"
#include "my_fs.h"
#include "my_bgs_components.h"
#include "my_json.h"
#include "my_puts.h"

static bool new_data(char const *str, int *id)
{
    if (*id == 0) {
        return true;
    }
    if (str[*id - 1] != '\\' && (str[*id] == 34 || str[*id] == '{' ||
        str[*id] == 21 || str[*id] == '[')) {
        return true;
    } else {
        return false;
    }
}

static any_t *init_ret_any(list_ptr_t *pile, any_t any, char const *str,
    int *id)
{
    any_t *retany = NULL;

    if (pop_data(pile, &any) == 84) {
        return NULL;
    }
    retany = any_dup(&any);
    if (retany == NULL) {
        return NULL;
    }
    destroy_pile(pile);
    if ((retany->type == INT || retany->type == FLOAT) &&
        (str[*id] == '}' || str[*id] == ']')) {
        *id = *id - 1;
    }
    return retany;
}

static any_t *parse_rec(char const *str, int *id, int strlen)
{
    char origin = str[*id];
    char end = '\0';
    any_t any = {0};
    list_ptr_t *pile = list_create();

    if (pile == NULL) {
        return NULL;
    }
    fill_data(origin, &end, &any);
    *id = (str[*id] == '\0' || str[*id] == ']' || str[*id] == '}') ? *id :
        *id + 1;
    for (; *id < strlen && str[*id] != end; *id = *id + 1) {
        if (new_data(str, id) == true &&
            list_add_to_end(pile, parse_rec(str, id, strlen)) == NULL) {
            return NULL;
        } else if (list_add_to_end(pile, create_any(str[*id])) == NULL) {
            return NULL;
        }
    }
    return init_ret_any(pile, any, str, id);
}

any_t *parse_json_file(char const path[])
{
    char *str = NULL;
    any_t *retany = NULL;

    if (path == NULL) {
        return NULL;
    }
    str = fs_get_content(path);
    if (str == NULL) {
        return NULL;
    }
    retany = parse_json_str(str);
    free(str);
    return retany;
}

any_t *parse_json_str(char const *str)
{
    int id = 0;
    any_t *ret_any = NULL;
    char *newstr = rm_space(str);

    if (str == NULL) {
        return NULL;
    }
    ret_any = parse_rec(newstr, &id, my_strlen(newstr));
    free(newstr);
    return ret_any;
}
