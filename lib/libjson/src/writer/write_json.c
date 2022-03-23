/*
** EPITECH PROJECT, 2022
** writer json
** File description:
** write json
*/

#include <fcntl.h>
#include <unistd.h>
#include "my_json.h"

int write_json(any_t *any, char const *path)
{
    int fd = 0;

    fd = open(path, O_WRONLY | O_TRUNC | O_CREAT);
    if (fd <= 0) {
        return (JS_ERR_INPUT);
    }
    prety_print(any, fd);
    close(fd);
    return JS_OK;
}
