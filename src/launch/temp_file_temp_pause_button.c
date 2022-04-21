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
    player_t *player = dico_t_get_value(win->components, "player");

    if (player == NULL || player->state == DYING || player->state == DIE) {
        return;
    }
    scene->pause = (scene->pause == true) ? false : true;
    set_stop(player);
    if (check_if_pop_up_true(scene->components, SETTINGS_MENU) == 0) {
        toggle_pop_up(win->components, "pause");
    }
}

int temp_pause_button(window_t *win, list_ptr_t *pause_menu,
    scene_t *scene, list_ptr_t *uid_elements)
{
    object_t *object = create_object(NULL, NULL, scene, 0);

    if (object == NULL ||
        object_set_sprite(object,
            "./assets/image/menu/main_menu/default_screen/Retour_button.png",
        (sfIntRect) {-1, -1, -1, -1}, (sfVector2f) {50, 50}) != BGS_OK) {
        return RET_ERR_INPUT;
    }
    list_add_to_end(uid_elements, object);
    object->is_visible = false;
    win->components = dico_t_add_data(win->components, "pause",
        pause_menu, free_pop_up);
    if (win->components == NULL || event_add_node(create_event(NULL, true,
        object, click_pause), (node_params_t)
        {sfMouseLeft, sfKeyA, MOUSE}) != BGS_OK) {
        return RET_ERR_MALLOC;
    }
    toggle_pop_up(win->components, "pause");
    return event_add_node(create_event(NULL, false, object, click_pause),
        (node_params_t) {sfMouseLeft, sfKeyEscape, KEY});
}
