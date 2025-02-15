#ifndef LIST_H
#define LIST_H

#include "door_struct.h"

typedef struct node {
    struct node* next;
    struct door* node_door;
} tNode;

tNode* init(struct door* doors, int count);
struct node* find_door(int door_id, struct node* root);
struct node* add_door(struct node* elem, struct door* door);
struct node* remove_door(struct node* elem, struct node* root);
void destroy(struct node* root);
tNode* get_memory(void);

#endif
