/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** update_data_json_inv
*/

#include "my_rpg.h"

int get_infinity_86(window_t *win)
{
    any_t *key_obj = NULL;
    any_t *actual_infinity_86 = NULL;

    if (win == NULL) {
        return RET_ERR_INPUT;
    }
    key_obj = dico_t_get_value(win->components, SAVE);
    if (key_obj == NULL) {
        return RET_ERR_MALLOC;
    }
    actual_infinity_86 = dico_t_get_value(key_obj->value.dict,
    INFINITY_86);
    actual_infinity_86->value.i += 1;
    if (key_obj == NULL) {
        return RET_ERR_MALLOC;
    }
    if (write_json(key_obj, STORY_DATA_PATH) != BGS_OK) {
        return RET_ERR_INPUT;
    }
}
