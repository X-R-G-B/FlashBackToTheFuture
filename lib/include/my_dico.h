/*
** EPITECH PROJECT, 2022
** libdico header
** File description:
** dico structure
*/

#ifndef LIB_DICO_H_
    #define LIB_DICO_H_

typedef struct dico_s dico_t;

struct dico_s {
    dico_t *next;
    dico_t *last;
    char key[255];
    void *value;
    void (*destroy)(void *data);
};

dico_t *dico_t_create(char const *key, void *value,
    void (*destroy)(void *data));

dico_t *dico_t_add_data(dico_t *dico, char const *key,
        void *value, void (*destroy)(void *value));

dico_t *dico_t_add_elem(dico_t *dico, dico_t *elem);

void *dico_t_pop_value(dico_t *elem, char const *key);

dico_t *dico_t_pop_elem(dico_t *elem, char const *key);

int dico_t_rem(dico_t *dico, char const *key);

int dico_t_destroy(dico_t *dico);

void *dico_t_get_value(dico_t *dico, char const *key);

dico_t *dico_t_get_elem(dico_t *dico, char const *key);

void dico_t_destroy_void(void *data);

#endif
