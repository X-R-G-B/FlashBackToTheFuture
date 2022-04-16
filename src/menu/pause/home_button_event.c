/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** home button event
*/

#include "my_rpg.h"
#include "main_menu.h"

static void check_type(dico_t *dico, list_t *elem, list_t **button_elem)
{
    float *pos = NULL;
    object_t *obj = elem->var;

    obj->is_visible = false;
    if (obj->type == SPRITE) {
        pos = get_any_float_array(dico_t_get_any(dico, "pos"));
        if (pos == NULL) {
            return;
        }
        obj->bigdata.sprite_bigdata.pos = (sfVector2f) {pos[1], pos[0]};
    } else if (obj->type == TEXT) {
        pos = get_any_float_array(dico_t_get_any(dico, "text pos"));
        if (pos == NULL) {
            return;
        }
        obj->bigdata.text_bigdata.pos = (sfVector2f) {pos[1], pos[0]};
    }
    if (elem->next != NULL && ((object_t *) elem->next->var)->type == SPRITE) {
        *button_elem = (*button_elem)->next;
    }
}

static void browse_list(list_ptr_t *setting_menu, list_ptr_t *buttons,
    scene_t *scene, scene_t *next_scene)
{
    list_t *elem = setting_menu->start;
    list_t *button_elem = buttons->start;
    any_t *dico = NULL;

    for (int i = 0; i < setting_menu->len; i++, elem = elem->next) {
        dico = button_elem->var;
        object_change_scene(elem->var, scene, next_scene);
        check_type(dico->value.dict, elem, &button_elem);
    }
}

static void move_setting_menu_to_main_menu(window_t *win, scene_t *scene)
{
    scene_t *next_scene = dico_t_get_value(win->scenes, "MAIN MENU");
    list_ptr_t *setting_menu = dico_t_get_value(scene->components,
        SETTINGS_MENU);
    any_t *buttons = NULL;
    any_t *setting_menu_data = parse_json_file(settings_data_path);

    if (next_scene == NULL || setting_menu == NULL ||
        setting_menu_data == NULL) {
        if (setting_menu_data != NULL) {
            destroy_any(setting_menu_data);
        }
        return;
    }
    buttons = dico_t_get_any(setting_menu_data->value.dict, "buttons");
    if (buttons == NULL || buttons->type != ARRAY) {
        return;
    }
    browse_list(setting_menu, buttons->value.array, scene, next_scene);
}

static void destroy_stage_components(scene_t *scene)
{
    list_ptr_t *uid_list = dico_t_get_value(scene->components, UID_ELEMENTS);

    if (uid_list != NULL) {
        free_list(uid_list);
    }
}

void home_button_off(object_t *obj, scene_t *scene, window_t *win,
    set_event_t *evt)
{
    player_t *player = dico_t_get_value(win->components, "player");

    if (scene->pause == false || player == NULL) {
        pressed_button_off(obj, scene, win, evt);
        return;
    }
    destroy_stage_components(scene);
    move_setting_menu_to_main_menu(win, scene);
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
