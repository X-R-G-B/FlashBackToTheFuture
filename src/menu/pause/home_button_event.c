/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** home button event
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "audio.h"
#include "main_menu.h"
#include "macro.h"
#include "player.h"

extern const char compo_dialog[];
extern const char can_play_dead_screen[];

static const char *TO_REMOVE_COMP_WIN[] = {PLAYER, PAUSE_MENU, DEAD_MESSAGE,
    DEAD_SCREEN, HUD_ELEMENTS, can_play_dead_screen, compo_dialog, NULL};

static const char *TO_REMOVE_SCENE[] = {INV_SCENE, NULL};

static void check_type(dico_t *dico, list_t *elem, list_t **button_elem)
{
    float *pos = NULL;
    object_t *obj = NULL;

    if (elem == NULL || elem->var == NULL) {
        return;
    }
    obj = elem->var;
    obj->is_visible = false;
    if (obj->type == SPRITE) {
        pos = get_any_float_array(dico_t_get_any(dico, "pos"));
    } else if (obj->type == TEXT) {
        pos = get_any_float_array(dico_t_get_any(dico, "text pos"));
    }
    if (pos != NULL) {
        obj->bigdata.text_bigdata.pos = (sfVector2f) {pos[1], pos[0]};
        free(pos);
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
    window_t *win = dico_t_get_value(scene->components, WINDOW);
    any_t *dico = NULL;

    if (win == NULL) {
        return;
    }
    for (int i = 0; i < setting_menu->len; i++, elem = elem->next) {
        dico = button_elem->var;
        object_change_scene(elem->var, scene, next_scene);
        if (i < setting_menu->len - 2) {
            check_type(dico->value.dict, elem, &button_elem);
        } else {
            replace_button(elem->var, dico->value.dict);
        }
    }
}

static void move_setting_menu_to_main_menu(window_t *win, scene_t *scene)
{
    scene_t *next_scene = dico_t_get_value(win->scenes, "MAIN MENU");
    list_ptr_t *setting_menu = dico_t_get_value(win->components,
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
    destroy_any(setting_menu_data);
}

void remove_components(window_t *win)
{
    for (int i = 0; TO_REMOVE_COMP_WIN[i] != NULL; i++) {
        win->components = dico_t_rem(win->components, TO_REMOVE_COMP_WIN[i]);
        if (win->components == NULL) {
            break;
        }
    }
    for (int i = 0; TO_REMOVE_SCENE[i] != NULL; i++) {
        win->scenes = dico_t_rem(win->scenes, TO_REMOVE_SCENE[i]);
        if (win->scenes == NULL) {
            break;
        }
    }
}

void go_to_home(scene_t *scene, window_t *win)
{
    player_t *player = NULL;

    if (scene == NULL || win == NULL) {
        return;
    }
    player = dico_t_get_value(win->components, PLAYER);
    if (player == NULL) {
        return;
    }
    move_setting_menu_to_main_menu(win, scene);
    window_change_scene(win, "MAIN MENU");
    toggle_music_in_scene(dico_t_get_value(win->scenes, "MAIN MENU"));
    list_add_to_end(win->to_remove, scene);
    sfView_setCenter(player->view,
        (sfVector2f) {WIN_SIZE_X / 2.0, WIN_SIZE_Y / 2.0});
    sfRenderWindow_setView(win->win, player->view);
    remove_components(win);
    list_add_to_end(win->to_remove, scene);
}
