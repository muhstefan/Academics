#include "list.h"

#include <stdio.h>

#include "door_struct.h"
#include "list_test.h"

int add_door_test(struct node *node_list, struct door *door_insert, int door_id) {
    if (node_list == NULL) {
        printf("FAIL\n");
        return 1;
    }  // тут 2 строчки если передали нулл или если дверь нулл
    if (door_insert == NULL) {
        printf("FAIL\n");
        return 1;
    }
    tNode *door_place = find_door(door_id, node_list);  // найти дверь
    if (door_place == NULL) {
        printf("FAIL\n");
        return 1;
    }  // если не смогли выход
    tNode *new_door = add_door(door_place, door_insert);  // запихать после места a дверь b
    if (new_door == NULL) {
        printf("FAIL\n");
        return 1;
    }  // если мы не смогли это сделать - выход
    else
        printf("SUCCESS\n");  // ееее
    return 0;
}

int remove_door_test(struct node *node_list, int remove_door_id) {
    if (node_list == NULL) {
        printf("FAIL\n");
        return 1;
    }  // тут 2 строчки если передали нулл или если дверь нулл
    tNode *door_place = find_door(remove_door_id, node_list);  // найти 13 дверь
    if (door_place == NULL) {
        printf("FAIL\n");
        return 1;
    }  // если не смогли выход
    tNode *new_node = remove_door(door_place, node_list);  // удалить эту дверь
    if (new_node == NULL) {
        printf("FAIL\n");
        return 1;
    }  // если мы не смогли это сделать - выход
    else
        printf("SUCCESS\n");
    return 0;
}
