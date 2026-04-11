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


typedef struct double_node_s {
    void *data;
    struct double_node_s *prev;
    struct double_node_s *next;
} dnode_t;

dnode_t *create_dnode(void *data);
void destroy_dnode(dnode_t *node, void (*free_data)(void *));


typedef struct binary_node_s {
    void *data;
    struct binary_node_s *left;
    struct binary_node_s *right;
} bnode_t;

bnode_t *create_bnode(void *data);
void destroy_bnode(bnode_t *node, void (*free_data)(void *));
void destroy_bnode_recursive(bnode_t *node, void (*free_data)(void *));

#endif /* !NODE_H_ */
