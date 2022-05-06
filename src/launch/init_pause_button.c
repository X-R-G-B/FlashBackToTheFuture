/*
** EPITECH PROJECT, 2022
** t
** File description:
** t
*/

#include "my_rpg.h"
#include "main_menu.h"

static void click_pause(__attribute__((unused)) object_t *obj, scene_t *scene,
    window_t *win, __attribute__((unused)) set_event_t *evt)
{
    player_t *player = dico_t_get_value(win->components, PLAYER);

    if (player == NULL || player->state == DYING || player->state == DIE ||
        player->state == IN_POP_UP) {
        return;
    }
    scene->pause = (scene->pause == true) ? false : true;
    set_stop(player);
    if (check_if_pop_up_true(win->components, SETTINGS_MENU) == 0) {
        toggle_pop_up(win->components, PAUSE_MENU);
    }
}

int init_pause_button(window_t *win, list_ptr_t *pause_menu,
    scene_t *scene, list_ptr_t *hud_elements)
{
    object_t *object = create_object(NULL, NULL, scene, 0);

    if (object == NULL) {
        return RET_ERR_INPUT;
    }
    list_add_to_end(hud_elements, object);
    win->components = dico_t_add_data(win->components, PAUSE_MENU,
        pause_menu, free_pop_up);
    if (win->components == NULL || event_add_node(create_event(NULL, true,
        object, click_pause), (node_params_t)
        {sfMouseLeft, sfKeyA, MOUSE}) != BGS_OK) {
        return RET_ERR_MALLOC;
    }
    toggle_pop_up(win->components, PAUSE_MENU);
    return event_add_node(create_event(NULL, false, object, click_pause),
        (node_params_t) {sfMouseLeft, sfKeyEscape, KEY});
}
