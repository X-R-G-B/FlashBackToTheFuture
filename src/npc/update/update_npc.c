/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** updat npc
*/

#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Window/Keyboard.h>
#include <stdbool.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Export.h>
#include "my_bgs.h"
#include "my_dico.h"
#include "my_json.h"
#include "my_macro.h"
#include "my_puts.h"
#include "npc.h"
#include "player.h"

static const sfKeyCode key_interract = sfKeyE;

static float refresh_rate = 1.0 / 10;

void call_callback_npc(object_t *npc, scene_t *scene, window_t *win)
{
    npc_data_func_t *callback = NULL;

    if (npc == NULL || scene == NULL || win == NULL) {
        return;
    }
    callback = dico_t_get_value(npc->components, npc_data_callback);
    if (callback == NULL) {
        return;
    }
    callback->callback(npc, scene, win);
}

static bool check_collid_player(object_t *npc, player_t *player,
    scene_t *scene, window_t *win)
{
    sfFloatRect pos[2] = {0};

    if (player == NULL || player->obj == NULL) {
        return (false);
    }
    pos[0] = sfSprite_getGlobalBounds(player->obj->drawable.sprite);
    pos[1] = sfSprite_getGlobalBounds(npc->drawable.sprite);
    if (sfFloatRect_intersects(pos, pos + 1, NULL) &&
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
        my_putstr(1, "need 'time' float set to 0.0");
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
    any_t *npcjson = NULL;

    if (win == NULL || obj == NULL) {
        return;
    }
    npcjson = dico_t_get_value(obj->components, npc_json);
    if (npcjson == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, PLAYER);
    check_collid_player(obj, player, scene, win);
    update_rect(obj, npcjson, dtime);
}
