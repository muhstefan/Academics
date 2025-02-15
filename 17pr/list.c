#include "list.h"

#include <stdio.h>
#include <stdlib.h>

tNode* init(struct door* doors, int count) {
    if (count <= 0) return NULL;  // Проверка на количество дверей

    tNode* head = get_memory();
    if (head == NULL) return NULL;
    head->node_door = doors;
    head->next = NULL;

    tNode* current = head;

    for (int i = 1; i < count; i++) {
        tNode* new_node = get_memory();
        if (new_node == NULL) return NULL;
        new_node->node_door = doors + i;
        new_node->next = NULL;

        current->next = new_node;
        current = new_node;
    }

    return head;
}

struct node* add_door(struct node* elem, struct door* door) {
    tNode* new_node = get_memory();
    if (new_node == NULL) return NULL;
    new_node->node_door = door;
    tNode* memory = elem->next;
    elem->next = new_node;
    new_node->next = memory;

    return new_node;
}

struct node* find_door(int door_id, struct node* root) {
    if (door_id < 0) return NULL;
    tNode* p = root;
    while (p != NULL) {
        if (p->node_door->id == door_id) return p;
        p = p->next;
    }
    return NULL;  // не нашли
}

struct node* remove_door(struct node* elem, struct node* root) {
    if (root == NULL || elem == NULL) return NULL;

    tNode* p = root;
    tNode* prev = NULL;

    while (p != NULL) {
        if (p == elem) {
            if (prev != NULL) {
                prev->next = p->next;
            } else {
                root = p->next;
            }
            free(p);
            return root;
        }
        prev = p;
        p = p->next;
    }
    return NULL;
}

void destroy(struct node* root) {
    tNode* current = root;
    tNode* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

tNode* get_memory(void) {
    tNode* pointer = (tNode*)malloc(sizeof(tNode));
    if (pointer == NULL)
        return NULL;  // не удалось выделить память
    else
        return pointer;
}
