/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** pause button event
*/

#include "my_rpg.h"
#include "my_bgs_button_generator.h"
#include "main_menu.h"

void settings_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    if (scene->pause == false) {
        pressed_button_off(obj, scene, win, evt);
        return;
    }
    toggle_pop_up(scene->components, SETTINGS_MENU);
    pressed_button_off(obj, scene, win, evt);
}

void restart_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    if (scene->pause == false) {
        pressed_button_off(obj, scene, win, evt);
        return;
    }
    pressed_button_off(obj, scene, win, evt);
}

void exit_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    if (scene->pause == false) {
        pressed_button_off(obj, scene, win, evt);
        return;
    }
    pressed_button_off(obj, scene, win, evt);
    sfRenderWindow_close(win->win);
}

void resume_event_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    if (scene->pause == false) {
        pressed_button_off(obj, scene, win, evt);
        return;
    }
    pressed_button_off(obj, scene, win, evt);
    set_is_visible_false(dico_t_get_value(scene->components, SETTINGS_MENU));
    toggle_pop_up(win->components, "pause");
    scene->pause = false;
}
<<<<<<< HEAD
=======

void home_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    player_t *player = dico_t_get_value(win->components, "player");

    if (scene->pause == false || player == NULL) {
        pressed_button_off(obj, scene, win, evt);
        return;
    }
    window_change_scene(win, "MAIN MENU");
    list_add_to_end(win->to_remove, scene);
    sfView_setCenter(player->view,
        (sfVector2f) {WIN_SIZE_X / 2, WIN_SIZE_Y / 2});
    sfRenderWindow_setView(win->win, player->view);
    win->components = dico_t_rem(win->components, "player");
    win->components = dico_t_rem(win->components, "pause");
    win->components = dico_t_rem(win->components, "dead_screen");
    win->components = dico_t_rem(win->components, "dead_message");
    win->components = dico_t_rem(win->components, SAVE);
    pressed_button_off(obj, scene, win, evt);
    list_add_to_end(win->to_remove, scene);
}
>>>>>>> dev
