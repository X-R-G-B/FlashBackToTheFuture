/*
** EPITECH PROJECT, 2021
** inlude list
** File description:
** chained list header
*/

#ifndef LIST_H_
    #define LIST_H_

typedef struct list list_t;
typedef struct list_ptr list_ptr_t;

struct list_ptr
{
    int len;
    list_t *start;
    list_t *end;
};

struct list
{
    void *var;
    list_t *back;
    list_t *next;
};

/**
** @brief create an empty list
**
** @return {
** NULL : malloc failed,
** list_ptr_t *: list has been created
** }
**/
list_ptr_t *list_create(void);

/**
** @brief add a void * to the end of the list_ptr_t
**
** @param list_ptr list in which the content will be added
** @param content content to add
**
** @return {
** NULL : list_ptr or content is NULL,
** NULL : malloc failed,
** list_t *: the node has been created and added
** }
**/
list_t *list_add_to_end(list_ptr_t *list_ptr, void *content);

/**
** @brief add a void * to the start of the list_ptr_t
**
** @param list_ptr list in which the content will be added
** @param content content to add
**
** @return {
** NULL : list_ptr or content is NULL,
** NULL : malloc failed,
** list_t *: the node has been created and added
** }
**/
list_t *list_add_to_start(list_ptr_t *list_ptr, void *content);

/**
** @brief add a void * to the index of the list_ptr_t
**
** @param list_ptr list in which the content will be added
** @param content content to add
** @param i the index i to insert the content
**
** @return {
** NULL : list_ptr or content is NULL,
** NULL : malloc failed,
** list_t *: the node has been created and added
** }
**/
list_t *list_add_to_i(list_ptr_t *list_ptr, void *content, int i);

/**
** @brief swap nodes at index x and y inside list_ptr_t
**
** @param list_ptr list in which the swap will be
** @param x index of a node
** @param y index of the other node
**/
void swap_two_elem(list_ptr_t *list_ptr, int x, int y);

/**
** @brief move the first node to the end of list_ptr_t
**
** @param list_ptr list in which the modification will be
**/
void move_first_elem_to_end(list_ptr_t *list_ptr);

/**
** @brief move last node to the start of list_ptr_t
**
** @param list_ptr list in which the modification will be
**/
void move_last_elem_to_start(list_ptr_t *list_ptr);

/**
** @brief reverse the order of all the list_ptr_t
**
** @param list_ptr list in which the modification will be
**/
void rev_list(list_ptr_t *list_ptr);

/**
** @brief get the content of the node at index x in list_ptr_t
**
** @param list_ptr list in which the element is
** @param x index to get the content of the node
**
** @return {
** NULL : list_ptr is NULL or index x is out of range
** void *: value in the node at index x
** }
**/
void *get_element_i_var(list_ptr_t *list_ptr, int x);

/**
** @brief get the node at index x in list_ptr_t
**
** @param list_ptr list in which the node is
** @param x index to get the node
**
** @return {
** NULL : list_ptr_t is NULL or index x is out of range
** void *: node at index x
** }
**/
list_t *get_element_i(list_ptr_t *list_ptr, int x);

/**
** @brief free all nodes (not the value inside) and list_ptr_t
**
** @param list_ptr list to free
**/
void free_list(list_ptr_t *list_ptr);

/**
** @brief free and remove the first element from list_ptr_t
**
** @param list_ptr list to remove the first elem
**/
void rm_fst_elem(list_ptr_t *list_ptr);

/**
** @brief free and remove the last element from list_ptr_t
**
** @param list_ptr list to remove the last elem
**/
void rm_last_elem(list_ptr_t *list_ptr);

/**
** @brief free and remove the element at index x from list_ptr_t
**
** @param list_ptr list to update
** @param x index to remove
**/
void rm_elem_i(list_ptr_t *list_ptr, int x);

/**
** @brief cast a node list_t value to a char *
**
** @param elem node in which the value will be cast
**
** @return {
** NULL : elem is NULL,
** char *: the value casted
** }
**/
char *str_from_list(list_t *elem);

/**
** @brief transform a char * with word separated by space to a list_ptr_t
**
** @param str string to parse
**
** @return {
** NULL : str is NULL,
** list_ptr_t *: parsed list
** }
**/
list_ptr_t *str_to_word_list(char *str);

#endif /* !LIST_H_ */
