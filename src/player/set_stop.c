/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** set stop
*/

#include "my_rpg.h"
#include "my_json.h"

static void apply_rect(player_t *player, const char *key, dico_t *dico)
{
    int *rect = get_any_int_array(dico_t_get_any(dico, key));

    if (rect == NULL) {
        return;
    }
    player->obj->bigdata.sprite_bigdata.rect = (sfIntRect) {rect[0], rect[1],
        rect[2], rect[3]};
    sfSprite_setOrigin(player->obj->drawable.sprite, (sfVector2f)
        {rect[2] / 2, rect[3] / 2});
    player->state = STOP;
}

static void check_state(player_t *player, any_t *stop)
{
    switch (player->dir) {
    case UP:
        apply_rect(player, "up", stop->value.dict);
        break;
    case RIGHT:
        apply_rect(player, "left", stop->value.dict);
        break;
    case LEFT:
        apply_rect(player, "left", stop->value.dict);
        break;
    case DOWN:
        apply_rect(player, "down", stop->value.dict);
        break;
    }
}

void set_stop(player_t *player)
{
    any_t *data = NULL;
    any_t *stop = NULL;

    if (player == NULL) {
        return;
    }
    data = dico_t_get_value(player->obj->components, "data");
    if (data == NULL) {
        return;
    }
    stop = dico_t_get_any(data->value.dict, "stop");
    if (stop == NULL) {
        return;
    }
    check_state(player, stop);
}
