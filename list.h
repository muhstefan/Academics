#ifndef LIST_H
#define LIST_H

#include "door_struct.h"



typedef struct node
{
    struct node *next;
    struct door node_door;
}tNode;

tNode* init(struct door* door, int count);

#endif