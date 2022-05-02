/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** update_data_json_inv
*/

#include "my_rpg.h"

void get_potions(window_t *win)
{
    any_t *potions = NULL;

    if (win == NULL) {
        return;
    }
    potions = dico_t_get_value(win->components, SAVE);
    potions = get_from_any(potions, "d", POTIONS);
    if (potions == NULL || potions->type != INT) {
        return;
    }
    potions->value.i += 1;
    if (write_json(potions, SAVE_PATH) != BGS_OK) {
        return;
    }
}

void get_infinity_86(window_t *win)
{
    any_t *key_obj = NULL;

    if (win == NULL) {
        return;
    }
    key_obj = dico_t_get_value(win->components, SAVE);
    key_obj = get_from_any(key_obj, "d", INFINITY_86);
    if (key_obj == NULL || key_obj->type != INT) {
        return;
    }
    key_obj->value.i += 1;
    if (write_json(key_obj, SAVE_PATH) != BGS_OK) {
        return;
    }
}
