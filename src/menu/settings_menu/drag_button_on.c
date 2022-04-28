/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** drag button off
*/

#include "audio.h"
#include "my_rpg.h"

static int get_delim(int *delim_start, int *delim_end, object_t *obj,
    window_t *win)
{
    if (win == NULL || obj == NULL) {
        return RET_ERR_INPUT;
    }
    *delim_start = (int) dico_t_get_value(obj->components, DELIM_START);
    *delim_end = (int) dico_t_get_value(obj->components, DELIM_END);
    if (*delim_start <= 0 || *delim_end <= 0 || *delim_end < *delim_start) {
        return RET_ERR_MALLOC;
    }
    return RET_OK;
}

static float get_view_left(window_t *win)
{
    player_t *player = NULL;
    sfVector2f view_pos = {0};

    if (win == NULL) {
        return -1;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL) {
        return 0;
    }
    view_pos = sfView_getCenter(player->view);
    return view_pos.x - (WIN_SIZE_X / 2);
}

void drag_button_on(object_t *obj, __attribute__((unused)) scene_t *scene,
    window_t *win, __attribute__((unused)) set_event_t *evt)
{
    int delim_start = -1;
    int delim_end = -1;
    sfVector2i mouse_pos_i = {0};
    sfVector2f mouse_pos = {0};
    float view_left = get_view_left(win);

    if (get_delim(&delim_start, &delim_end, obj, win) != RET_OK) {
        return;
    }
    sfSprite_setScale(obj->drawable.sprite, (sfVector2f) {1.0, 1.0});
    mouse_pos_i = sfMouse_getPositionRenderWindow(win->win);
    mouse_pos = (sfVector2f) {mouse_pos_i.x, mouse_pos_i.y};
    if (mouse_pos.x < delim_start || mouse_pos.x > delim_end) {
        return;
    }
    obj->bigdata.sprite_bigdata.pos.x = mouse_pos.x + view_left;
}
