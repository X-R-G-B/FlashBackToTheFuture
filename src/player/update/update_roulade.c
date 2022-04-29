/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** update roulade
*/

#include "my_rpg.h"

static const char roulade_key[] = "roulade";
static const char rect_key[] = "rect";
static const char time_key[] = "time";

static void apply_rect(player_t *player, int current_id)
{
    any_t *player_data = dico_t_get_value(player->obj->components, PLAYER_DATA);
    int *rect = get_any_int_array(get_from_any(player_data, "d", roulade_key,
        rect_key, player->dir, current_id));
    any_t *rect_list = get_from_any(player_data, "d", roulade_key, rect_key,
        player->dir, current_id);

    if (rect == NULL || rect_list == NULL || rect_list->type != ARRAY ||
        rect_list->value.array->len != ARRAY) {
        if (rect != NULL) {
            free(rect);
        }
        return;
    }
    player->obj->bigdata.sprite_bigdata.rect = (sfIntRect) {rect[0], rect[1],
        rect[2], rect[3]};
    sfSprite_setOrigin(player->obj->drawable.sprite,
        (sfVector2f) {rect[2] / 2, rect[3] / 2});
    free(rect);
}

static void check_end(float *since_start, player_t *player)
{
    any_t *player_data = dico_t_get_value(player->obj->components, PLAYER_DATA);
    any_t *time = get_from_any(player_data, "d", );
}

void update_roulade(player_t *player, scene_t *scene, window_t *win,
    float dtime)
{
    static float since_start = 0;
    static float time = 0;
    static int current_id = 0;

    if (player == NULL || scene == NULL || win == NULL) {
        return;
    }
    time += dtime;
    since_start += dtime;
    check_end(&since_start, player);
    apply_rect(player, current_id);
    increment_id();
}
