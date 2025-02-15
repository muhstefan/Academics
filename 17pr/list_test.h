#ifndef LIST_TEST_H
#define LIST_TEST_H

#include "door_struct.h"
#include "list.h"

int add_door_test(struct node *node_list, struct door *door_insert, int door_id);
int remove_door_test(struct node *node_list, int remove_door_id);

#endif
