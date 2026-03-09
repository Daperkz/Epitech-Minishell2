/*
** EPITECH PROJECT, 2026
** node.h
** File description:
** node
*/

#ifndef NODE_H_
    #define NODE_H_


typedef struct node_s {
    void *data;
    struct node_s *next;
} node_t;

node_t *create_node(void *data);
void destroy_node(node_t *node, void (*free_data)(void *));


typedef struct dnode_s {
    void *data;
    struct dnode_s *prev;
    struct dnode_s *next;
} dnode_t;

dnode_t *create_dnode(void *data);
void destroy_dnode(dnode_t *node, void (*free_data)(void *));

#endif /* !NODE_H_ */
