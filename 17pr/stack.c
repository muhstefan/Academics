#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

tStackNode* init(int init_data) {
    tStackNode* head = get_memory();
    if (head == NULL) return NULL;
    head->data = init_data;
    head->next = NULL;
    return head;
}

tStackNode* push(tStackNode* head, int init_data) {
    tStackNode* new_node = get_memory();
    if (new_node == NULL) return NULL;
    new_node->data = init_data;
    new_node->next = head;
    return new_node;
}

int pop(tStackNode** stack) {
    if (*stack == NULL) return -1;
    tStackNode* temp = *stack;
    int popped_data = temp->data;
    *stack = (*stack)->next;
    free(temp);
    return popped_data;
}

void destroy(tStackNode* stack) {
    tStackNode* current = stack;
    while (current != NULL) {
        tStackNode* next_node = current->next;
        free(current);
        current = next_node;
    }
}

tStackNode* get_memory(void) {
    tStackNode* pointer = (tStackNode*)malloc(sizeof(tStackNode));
    if (pointer == NULL)
        return NULL;  // не удалось выделить память
    else
        return pointer;
}
