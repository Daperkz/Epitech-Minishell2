/*
** EPITECH PROJECT, 2026
** queue.h
** File description:
** queue
*/

#ifndef QUEUE_H_
    #define QUEUE_H_

    #include "double_linked_list.h"

typedef dll_t queue_t;

    #define QUEUE_CREATE() dll_create()
    #define QUEUE_DESTROY(q, free) dll_destroy(q, free)
    #define QUEUE_ENQUEUE(q, data) dll_insert(q, data)
    #define QUEUE_DEQUEUE(q) dll_pop_tail(q)
    #define QUEUE_IS_EMPTY(q) ((q)->len == 0)


#endif /* !QUEUE_H_ */
