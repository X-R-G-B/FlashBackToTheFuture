/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** remove an object
*/

#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <stdlib.h>
#include "my_bgs.h"

static void remove_sprite(object_t *object)
{
    sfSprite_destroy(object->drawable.sprite);
    sfTexture_destroy(object->bigdata.sprite_bigdata.texture);
}

static void remove_text(object_t *object)
{
    sfText_destroy(object->drawable.text);
    sfFont_destroy(object->bigdata.text_bigdata.font);
}

static void remove_audio(object_t *obj)
{
    if (obj->type == AUDIO) {
        sfMusic_setLoop(obj->drawable.music, sfFalse);
        sfMusic_stop(obj->drawable.music);
        sfMusic_destroy(obj->drawable.music);
    } else {
        sfSound_setLoop(obj->drawable.sound, sfFalse);
        sfSound_stop(obj->drawable.sound);
        sfSound_destroy(obj->drawable.sound);
        sfSoundBuffer_destroy(obj->bigdata.sound_bigdata.buffer);
    }
}

void remove_object(object_t *object)
{
    if (object == NULL) {
        return;
    }
    switch (object->type) {
        case SPRITE:
            remove_sprite(object);
            break;
        case TEXT:
            remove_text(object);
            break;
        case AUDIO:
        case SOUND:
            remove_audio(object);
            break;
        default:
            break;
    }
    dico_t_destroy(object->components);
    free(object);
}
