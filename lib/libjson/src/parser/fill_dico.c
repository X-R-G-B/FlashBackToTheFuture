/*
** EPITECH PROJECT, 2022
** json parser
** File description:
** fill dico
*/

#include <stdlib.h>
#include "my_puts.h"
#include "my_json.h"
#include "my_strings.h"

int create_dico(any_t **any, any_t **key, any_t **data)
{
    if (*key != NULL && *data != NULL) {
        (*any)->value.dict = dico_t_add_data((*any)->value.dict,
            (*key)->value.str, *data, &destroy_any);
        if ((*any)->value.dict == NULL) {
            return JS_ERR_MALLOC;
        }
        destroy_any(*key);
        *key = NULL;
        *data = NULL;
    }
    return JS_OK;
}

int fill_dico(list_ptr_t *pile, any_t *any)
{
    list_t *elem = pile->start;
    any_t *cur_any = NULL;
    any_t *key = NULL;
    any_t *data = NULL;

    for (int i = 0; i < pile->len; i++, elem = elem->next) {
        cur_any = ((any_t *) elem->var);
        if (cur_any->type != CHAR && key == NULL) {
            key = any_dup(cur_any);
        } else if (cur_any->type != CHAR && key != NULL && data == NULL) {
            data = any_dup(cur_any);
        }
        if (create_dico(&any, &key, &data) != JS_OK) {
            return JS_ERR_MALLOC;
        }
    }
    return JS_OK;
}
