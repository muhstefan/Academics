#include <stdio.h>
#include <stdlib.h> 
#include "list.h"

tNode* init(struct door* door, int count) {
    if (count <= 0) return NULL; // Проверка на количество дверей

    tNode *head = (tNode*)malloc(sizeof(tNode));
    head->node_door = door[0];
    head->next = NULL;

    tNode *current = head;

    for (int i = 1; i < count; i++) {
        tNode *new_node = (tNode*)malloc(sizeof(tNode));
        new_node->node_door = door[i];
        new_node->next = NULL; 

        current->next = new_node; 
        current = new_node; 
    }

    return head; 
}


// struct node* add_door(struct node* elem, struct door* door){

// }