/*
** EPITECH PROJECT, 2022
** FlashBackToTheFuture
** File description:
** update_ninho
*/

#include "npc.h"
#include "my_rpg.h"
#include "macro.h"
#include "stage.h"
#include "player.h"
#include "audio.h"

extern const char npc_path_key[];

static const sfKeyCode key_interract = sfKeyE;

static void check_next_stage_event(object_t *obj, window_t *win,
    __attribute__((unused)) scene_t *scene)
{
    player_t *player = dico_t_get_value(win->components, PLAYER);
    sfFloatRect player_rect = {0};
    sfFloatRect npc_rect = sfSprite_getGlobalBounds(obj->drawable.sprite);

    if (player == NULL) {
        return;
    }
    player_rect = sfSprite_getGlobalBounds(player->obj->drawable.sprite);
    if (sfFloatRect_intersects(&player_rect, &npc_rect, NULL) == sfTrue &&
        sfKeyboard_isKeyPressed(key_interract) == sfTrue) {
        play_sound(win, NINHO);
    }
}

static void ninho_npc_update(object_t *obj, scene_t *scene, window_t *win,
    float dtime)
{
    check_next_stage_event(obj, win, scene);
    update_npc(obj, scene, win, dtime);
}

void update_ninho(object_t *obj, scene_t *scene, window_t *win,
    __attribute__((unused)) float dtime)
{
    char *npc_path = NULL;
    object_t *npc = NULL;

    if (obj == NULL || obj->components == NULL ||
            scene == NULL || win == NULL) {
        return;
    }
    npc_path = dico_t_get_value(obj->components, npc_path_key);
    if (npc_path == NULL) {
        return;
    }
    npc = add_npc(scene, npc_path, obj->bigdata.sprite_bigdata.pos,
        &callback_npc);
    npc->update = &ninho_npc_update;
    obj->components = dico_t_rem(obj->components, npc_path_key);
}
