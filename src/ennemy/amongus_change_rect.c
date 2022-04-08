/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** change the float rect of amongus
*/

#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>
#include <math.h>
#include "my_bgs.h"
#include "my_dico.h"
#include "my_json.h"
#include "my_rpg.h"
#include "my_strings.h"
#include "macro.h"

static const double pi = 3.1415926535;

static sfVector2f get_position_player(window_t *win)
{
    sfVector2f pos = {500, 500};
    player_t *player = dico_t_get_value(win->components, "player");

    if (player == NULL) {
        return (pos);
    }
    pos = player->obj->bigdata.sprite_bigdata.pos;
    return (pos);
}

static void change_among_us_state(object_t *obj, window_t *win, any_t *state)
{
    sfVector2f dir = get_position_player(win);
    sfVector2f cur = sfSprite_getPosition(obj->drawable.sprite);
    double angle = 0;

    angle = atan2(cur.y - dir.y, cur.x - dir.x) * 180 / pi;
    if (45 <= angle && angle < 135 && my_strcmp(state->value.str, GO_UP)) {
        my_strealloc(&state->value.str, GO_UP);
    }
    if ((135 <= angle || -135 > angle) && my_strcmp(state->value.str, GO_RT)) {
        my_strealloc(&state->value.str, GO_RT);
    }
    if (-135 <= angle && angle < -45 && my_strcmp(state->value.str, GO_DN)) {
        my_strealloc(&state->value.str, GO_DN);
    }
    if (-45 <= angle && angle < 45 && my_strcmp(state->value.str, GO_LT)) {
        my_strealloc(&state->value.str, GO_LT);
    }
}

static float *get_amongus_rect(any_t *dico, object_t *obj, window_t *win)
{
    static float rect[4] = {0};
    any_t *state = get_from_any(dico, "d", "state");
    any_t *tmp = NULL;

    if (dico == NULL || state == NULL || state->type != STR) {
        return (NULL);
    }
    change_among_us_state(obj, win, state);
    for (int i = 0; i < 4; i++) {
        tmp = get_from_any(dico, "da", state->value.str, i);
        if (tmp == NULL || tmp->type != FLOAT) {
            return (NULL);
        }
        rect[i] = tmp->value.f;
    }
    return (rect);
}

int change_amongus_rect(any_t *dico, object_t *obj, window_t *win)
{
    sfIntRect rect = {0};
    float *rect_any = NULL;
    any_t *current = get_from_any(dico, "d", "current");
    any_t *nb_current = get_from_any(dico, "d", "max_current");

    rect_any = get_amongus_rect(dico, obj, win);
    if (rect_any == NULL || current == NULL || current->type != INT ||
            nb_current == NULL || nb_current->type != INT) {
        return (BGS_ERR_INPUT);
    }
    rect = (sfIntRect) {.left = rect_any[0], .top = rect_any[1],
            .width = rect_any[2], .height = rect_any[3]};
    rect.left += rect.width * current->value.i;
    obj->bigdata.sprite_bigdata.rect = rect;
    sfSprite_setOrigin(obj->drawable.sprite,
            (sfVector2f) {rect.width / 2.0, rect.height / 2.0});
    current->value.i = (current->value.i + 1) % nb_current->value.i;
    return (BGS_OK);
}
