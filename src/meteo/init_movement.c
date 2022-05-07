/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init mouvements of dirt
*/

#include "list.h"
#include "macro.h"
#include "my_bgs.h"
#include "my_bgs_framebuffer.h"
#include "my_dico.h"
#include "my_rpg.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/View.h>
#include <SFML/System/Vector2.h>
#include <stdbool.h>
#include <stdlib.h>

static void update_buf_player(__attribute__((unused)) object_t *obj,
    __attribute__((unused)) scene_t *scene, window_t *win,
    float dtime)
{
    player_t *player = NULL;

    if (win == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL) {
        return;
    }
    update_framebuffer(player->buf, dtime);
}

static void display_buf_player(__attribute__((unused)) object_t *obj,
    dico_t *scene_comp, dico_t *win_comp,
    sfRenderWindow *window)
{
    player_t *player = NULL;
    window_t *win = NULL;

    if (win_comp == NULL || window == NULL) {
        return;
    }
    player = dico_t_get_value(win_comp, PLAYER);
    win = dico_t_get_value(scene_comp, WINDOW);
    if (player == NULL || player->buf == NULL || win == NULL ||
            player->view == NULL) {
        return;
    }
    player->buf->pos_on_win = sfView_getCenter(player->view);
    player->buf->pos_on_win.x -= WIN_SIZE_X / 2.0;
    player->buf->pos_on_win.y -= WIN_SIZE_Y / 2.0;
    draw_framebuffer(win, player->buf);
}

static int add_to_hud_elem(window_t *win, object_t *obj)
{
    list_ptr_t *list_objs = NULL;

    list_objs = dico_t_get_value(win->components, HUD_ELEMENTS);
    if (list_objs == NULL) {
        return (RET_ERR_INPUT);
    }
    list_add_to_end(list_objs, obj);
    return (RET_OK);
}

int init_movement(player_t *player, window_t *win, scene_t *scene)
{
    object_t *obj = NULL;

    if (player == NULL || win == NULL || scene == NULL) {
        return (RET_ERR_INPUT);
    }
    player->buf = create_framebuffer(WIN_SIZE_X, WIN_SIZE_Y,
        (sfVector2f) {0, 0});
    if (player->buf == NULL) {
        return (RET_ERR_MALLOC);
    }
    obj = create_object(update_buf_player, display_buf_player, scene,
        LAYER_PLAYER + 1);
    if (object_set_custom(obj) != BGS_OK) {
        return (RET_ERR_MALLOC);
    }
    return (add_to_hud_elem(win, obj));
}
