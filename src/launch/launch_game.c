/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init game
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "audio.h"
#include "main_menu.h"

static int get_save(window_t *win)
{
    any_t *save = NULL;

    if (win == NULL) {
        return RET_ERR_MALLOC;
    }
    save = parse_json_file(SAVE_PATH);
    if (save == NULL || save->type != DICT) {
        return RET_ERR_INPUT;
    }
    win->components = dico_t_add_data(win->components, SAVE, save, destroy_any);
    return (win->components == NULL) ? RET_ERR_MALLOC : RET_OK;
}

int launch_game(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    window_t *win = create_window(mode, "My_Rpg", sfResize | sfClose |
        sfFullscreen);

    window_set_icon(win, ICON_PATH);
    srand(0);
    if (get_save(win) != RET_OK || init_audio_list(win) ||
        init_menu(win) != RET_OK ||
        window_change_scene(win, "MAIN MENU") != BGS_OK ||
        loop(win) != BGS_OK) {
        return 84;
    }
    remove_window(win);
    return RET_OK;
}
