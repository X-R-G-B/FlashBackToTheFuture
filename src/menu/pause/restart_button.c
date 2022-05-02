/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** restart button 
*/

#include "my_rpg.h"
#include "ennemies.h"
#include "main_menu.h"

static void restart_player_state(window_t *win)
{
    player_t *player = dico_t_get_value(win->components, PLAYER);
    any_t *stats = NULL;
    any_t *life = NULL;
    any_t *energy = NULL;

    if (player == NULL || player->obj == NULL) {
        return;
    }
    player->dir = DOWN;
    set_stop(player);
    stats = dico_t_get_value(player->obj->components, PLAYER_STATS);
    life = get_from_any(stats, "d", "max_life");
    energy = get_from_any(stats, "d", "max_energy");
    if (life != NULL && life->type == FLOAT) {
        player->life = life->value.f;
    }
    if (energy != NULL && energy->type == FLOAT) {
        player->energy = energy->value.f;
    }
}

static void restart_spawner(scene_t *scene)
{
    list_t *elem = NULL;
    list_ptr_t *spawner_list = dico_t_get_value(scene->components,
        SPAWNER_LIST);
    object_t *obj = NULL;

    if (spawner_list == NULL) {
        return;
    }
    elem = spawner_list->start;
    for (int i = 0; i < spawner_list->len && elem->var != NULL; i++,
        elem = elem->next) {
        obj = elem->var;
        obj->components = dico_t_rem(obj->components, ENNEMY_KEY);
    }
}

void restart_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    if (obj == NULL || scene == NULL || scene->pause == false || win == NULL ||
        obj->is_visible == false) {
        win->click = NULL;
        pressed_button_off(obj, scene, win, evt);
        return;
    }
    restart_spawner(scene);
    replace_objects(win, scene);
    restart_player_state(win);
    scene->pause = false;
    set_is_visible_false(dico_t_get_value(win->components, PAUSE_MENU));
    set_is_visible_false(dico_t_get_value(win->components, SETTINGS_MENU));
    pressed_button_off(obj, scene, win, evt);
}
