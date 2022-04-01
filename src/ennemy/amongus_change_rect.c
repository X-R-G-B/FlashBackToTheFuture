/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** change the float rect of amongus
*/

#include <SFML/Graphics/Rect.h>
#include "my_bgs.h"
#include "my_dico.h"
#include "my_json.h"

static void change_among_us_state(any_t *dico, object_t *obj, window_t *win)
{
    any_t *state = get_from_any(dico, "d", "state");

    if (state == NULL || state->type != STR) {
        return;
    }
}

static float *get_amongus_rect(any_t *dico)
{
    static float rect[4] = {0};
    any_t *state = get_from_any(dico, "d", "state");
    any_t *tmp = NULL;

    if (dico == NULL || state == NULL || state->type != STR) {
        return (NULL);
    }
    for (int i = 0; i < 4; i++) {
        tmp = get_from_any(dico, "da", state->value.str, i);
        if (tmp == NULL || tmp->type != FLOAT) {
            return (NULL);
        }
        rect[i] = tmp->value.f;
    }
    return (rect);
}

int change_amongus_rect(any_t *dico, object_t *obj)
{
    sfIntRect rect = {0};
    float *rect_any = NULL;
    any_t *current = get_from_any(dico, "d", "current");
    any_t *nb_current = get_from_any(dico, "d", "max_current");

    rect_any = get_amongus_rect(dico);
    if (rect_any == NULL || current == NULL || current->type != INT ||
            nb_current == NULL || nb_current->type != INT) {
        return (BGS_ERR_INPUT);
    }
    rect = (sfIntRect) {.left = rect_any[0], .top = rect_any[1],
            .width = rect_any[2], .height = rect_any[3]};
    rect.left += rect.width * current->value.i;
    obj->bigdata.sprite_bigdata.rect = rect;
    sfSprite_setOrigin(obj->drawable.sprite,
            (sfVector2f) {rect.width / 2, rect.height / 2});
    current->value.i = (current->value.i + 1) % nb_current->value.i;
    return (BGS_OK);
}
