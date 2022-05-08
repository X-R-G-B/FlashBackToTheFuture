/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** update hurt
*/

#include <SFML/Graphics/View.h>
#include <SFML/System/Vector2.h>
#include <stdbool.h>
#include "ennemies.h"
#include "my_dico.h"
#include "my_json.h"
#include "math.h"
#include "maths_function.h"
#include "player.h"

static const float time_nulll = 1;

static const float coef = 1000;

const char data_directions[] = "dirrections player hurt";

static const int nb_intervals = 100;

static const float update_time = 1.0 / 30.0;

static const int coef_vector_new = 3;

static void update_move_player(player_t *player, window_t *win, sfVector2f new)
{
    ennemy_t enn = {0};
    sfVector2f delta_x = {new.x / nb_intervals, new.y / nb_intervals};

    enn = (ennemy_t) {player->state, player->dir, 1, player->obj, 0, 0, 0, 1};
    for (int i = 0; i < nb_intervals; i++) {
        if (check_wall(&enn, new, win) == true || player->view == NULL) {
            break;
        }
        player->obj->bigdata.sprite_bigdata.pos.x += delta_x.x;
        player->obj->bigdata.sprite_bigdata.pos.y += delta_x.x;
        increment_hud_pos(win, get_distance(
            player->obj->bigdata.sprite_bigdata.pos,
            sfView_getCenter(player->view)));
        sfView_setCenter(player->view, player->obj->bigdata.sprite_bigdata.pos);
    }
}

static void update_player_rollback(player_t *player, float since_start,
    window_t *win, float dtime)
{
    sfVector2f *dirrection = NULL;
    static float time_up = 0;
    sfVector2f new = {0};

    time_up += dtime;
    if (time_up < update_time) {
        return;
    }
    time_up -= update_time;
    dirrection = dico_t_get_value(player->obj->components, data_directions);
    if (dirrection == NULL) {
        return;
    }
    new = (sfVector2f) {dirrection->x / since_start,
        dirrection->y / since_start};
    new.x *= coef_vector_new;
    new.y *= coef_vector_new;
    update_move_player(player, win, new);
}

static void check_blink_time_end(float *since_start, float dtime, window_t *win,
    player_t *player)
{
    any_t *data = dico_t_get_value(player->obj->components, PLAYER_DATA);
    any_t *blink_time = get_from_any(data, "d", "blink time");

    if (blink_time == NULL || blink_time->type != FLOAT) {
        return;
    }
    *since_start += dtime;
    if (*since_start < time_nulll) {
        update_player_rollback(player, *since_start * (dtime * coef), win,
            dtime);
    } else if (*since_start >= blink_time->value.f) {
        *since_start = 0;
        player->obj->components = dico_t_rem(player->obj->components, hurt_key);
        player->obj->components = dico_t_rem(player->obj->components,
            data_directions);
    }
}

void update_hurt(player_t *player, __attribute__((unused)) scene_t *scene,
    __attribute__((unused)) window_t *win, float dtime)
{
    static float since_start = 0;
    any_t *data = NULL;

    if (player == NULL || player->obj == NULL) {
        return;
    }
    data = dico_t_get_value(player->obj->components, PLAYER_DATA);
    if (data == NULL) {
        return;
    }
    check_blink_time_end(&since_start, dtime, win, player);
}
