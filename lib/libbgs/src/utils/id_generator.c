/*
** EPITECH PROJECT, 2022
** defender
** File description:
** id_generator
*/

#include "my_strings.h"

unsigned char *get_id_generator(char dest[255])
{
    static unsigned char keys[255] = {0};
    static int index = 0;

    if (keys[index] >= 254) {
        index++;
    }
    if (index >= 254) {
        for (int i = 1; i < index; i++) {
            keys[i] = 0;
        }
        keys[0] += 1;
        index = 1;
    }
    keys[index] += 1;
    my_strcpy(dest, (char *) keys);
    return (keys);
}

char *get_id_generator_cat(char dest[255])
{
    int size = 0;
    char id[255];
    int i = 0;

    get_id_generator(id);
    size = my_strlen(dest);
    for (i = size; i < 254 && id[i - size] != '\0'; i++) {
        dest[i] = id[i - size];
    }
    dest[i] = '\0';
    return (dest);
}
