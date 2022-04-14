/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** home button event
*/

#include "my_rpg.h"

static void move_setting_menu_to_main_menu()
{
    
}

void home_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    player_t *player = dico_t_get_value(win->components, "player");

    if (scene->pause == false || player == NULL) {
        pressed_button_off(obj, scene, win, evt);
        return;
    }
    move_setting_menu_to_main_menu();
    window_change_scene(win, "MAIN MENU");
    list_add_to_end(win->to_remove, scene);
    sfView_setCenter(player->view,
        (sfVector2f) {WIN_SIZE_X / 2, WIN_SIZE_Y / 2});
    sfRenderWindow_setView(win->win, player->view);
    win->components = dico_t_rem(win->components, "player");
    win->components = dico_t_rem(win->components, "pause");
    win->components = dico_t_rem(win->components, SAVE);
    pressed_button_off(obj, scene, win, evt);
    list_add_to_end(win->to_remove, scene);
}
