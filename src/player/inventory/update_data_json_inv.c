/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** update_data_json_inv
*/

#include "my_rpg.h"

void get_potions(window_t *win)
{
    any_t *key_obj = NULL;
    any_t *actual_potions = NULL;

    if (win == NULL) {
        return;
    }
    key_obj = dico_t_get_value(win->components, SAVE);
    if (key_obj == NULL) {
        return;
    }
    actual_potions = dico_t_get_value(key_obj->value.dict,
    POTIONS);
    actual_potions->value.i += 1;
    if (key_obj == NULL) {
        return;
    }
    if (write_json(key_obj, SAVE_PATH) != BGS_OK) {
        return;
    }
}

void get_infinity_86(window_t *win)
{
    any_t *key_obj = NULL;
    any_t *actual_infinity_86 = NULL;

    if (win == NULL) {
        return;
    }
    key_obj = dico_t_get_value(win->components, SAVE);
    if (key_obj == NULL) {
        return;
    }
    actual_infinity_86 = dico_t_get_value(key_obj->value.dict,
    INFINITY_86);
    actual_infinity_86->value.i += 1;
    if (key_obj == NULL) {
        return;
    }
    if (write_json(key_obj, SAVE_PATH) != BGS_OK) {
        return;
    }
}
