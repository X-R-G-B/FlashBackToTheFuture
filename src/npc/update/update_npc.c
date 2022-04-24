/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** updat npc
*/

#include <SFML/Window/Keyboard.h>
#include <stdbool.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Export.h>
#include "my_bgs.h"
#include "my_dico.h"
#include "my_json.h"
#include "my_puts.h"
#include "my_rpg.h"
#include "npc.h"

static const sfKeyCode key_interract = sfKeyA;

static float refresh_rate = 1.0 / 10;

static void call_callback_npc(object_t *npc, scene_t *scene, window_t *win)
{
    npc_data_func_t *callback = NULL;

    callback = dico_t_get_value(npc->components, npc_data_callback);
    if (callback == NULL) {
        return;
    }
    callback->callback(npc, scene, win);
}

static bool check_collid_player(object_t *npc, player_t *player,
    scene_t *scene, window_t *win)
{
    sfVector2i pos[2] = {0};

    if (player == NULL || player->obj == NULL) {
        return (false);
    }
    pos[0] = (sfVector2i) {
        .x = (int) (player->obj->bigdata.sprite_bigdata.pos.x) / SQUARE_SIZE,
        .y = (int) (player->obj->bigdata.sprite_bigdata.pos.y) / SQUARE_SIZE,
    };
    pos[1] = (sfVector2i) {
        .x = (int) (npc->bigdata.sprite_bigdata.pos.x) / SQUARE_SIZE,
        .y = (int) (npc->bigdata.sprite_bigdata.pos.y) / SQUARE_SIZE,
    };
    if (pos[0].x == pos[1].x && pos[0].y == pos[1].y &&
            sfKeyboard_isKeyPressed(key_interract) == sfTrue) {
        call_callback_npc(npc, scene, win);
        return (true);
    }
    return (false);
}

static bool update_rect(object_t *npc, any_t *npcjson, float dtime)
{
    any_t *current = NULL;
    any_t *rectjson = NULL;
    any_t *time = NULL;

    time = get_from_any(npcjson, "d", "time");
    current = get_from_any(npcjson, "d", "current");
    if (time == NULL || time->type != FLOAT) {
        my_putstr(1, "need 'time' float set to 0");
        return (false);
    }
    rectjson = get_from_any(npcjson, "d", "rect");
    time->value.f += dtime;
    if (time->value.f < refresh_rate) {
        return (false);
    }
    time->value.f -= refresh_rate;
    aplly_rect_npc(rectjson, current, npc);
    return (true);
}

void update_npc(object_t *obj, scene_t *scene, window_t *win,
    float dtime)
{
    player_t *player = NULL;
    any_t *time = NULL;
    any_t *npcjson = NULL;

    if (win == NULL || obj == NULL) {
        return;
    }
    npcjson = dico_t_get_value(obj->components, npc_json);
    time = get_from_any(npcjson, "d", "time");
    if (time == NULL || time->type != FLOAT) {
        my_putstr(1, "you need to provide float 'time' in the npc json");
        return;
    }
    player = dico_t_get_value(win->components, "player");
    check_collid_player(obj, player, scene, win);
    update_rect(obj, time, dtime);
}
