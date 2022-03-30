/*
** EPITECH PROJECT, 2022
** LIBBGS
** File description:
** set object type sound
*/

#include "my_bgs.h"
#include "my_bgs_components.h"
#include <SFML/Audio/SoundBuffer.h>

int object_set_sound(object_t *object, char const *path, bool play_now,
    bool loop_now)
{
    if (object == NULL || path == NULL) {
        return BGS_ERR_INPUT;
    }
    object->bigdata.sound_bigdata.buffer = sfSoundBuffer_createFromFile(path);
    if (object->bigdata.sound_bigdata.buffer == NULL) {
        return BGS_ERR_PATH;
    }
    object->drawable.sound = sfSound_create();
    if (object->drawable.sound == NULL) {
        return BGS_ERR_MALLOC;
    }
    if (play_now == true) {
        sfSound_play(object->drawable.sound);
    }
    if (loop_now == true) {
        sfSound_setLoop(object->drawable.sound, sfTrue);
    }
    object->type = SOUND;
    return BGS_OK;
}
