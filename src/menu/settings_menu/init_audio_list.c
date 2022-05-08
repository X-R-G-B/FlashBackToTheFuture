/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init audio list
*/

#include "audio.h"
#include "my_bgs_components.h"
#include "my_rpg.h"
#include "macro.h"

int init_audio_list(window_t *win)
{
    list_ptr_t *audio_list = NULL;
    list_ptr_t *sound_list = NULL;

    if (win == NULL) {
        return RET_ERR_INPUT;
    }
    audio_list = list_create();
    sound_list = list_create();
    if (audio_list == NULL || sound_list == NULL || window_add_component(win,
        audio_list, AUDIO_LIST, free_pop_up) != RET_OK ||
        window_add_component(win, sound_list, SOUND_LIST,
        free_pop_up) != RET_OK) {
        return RET_ERR_MALLOC;
    }
    return RET_OK;
}
