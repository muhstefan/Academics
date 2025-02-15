#ifndef STACK_H
#define STACK_H

typedef struct stack_node {
    struct stack_node *next;
    int data;
} tStackNode;

tStackNode *init(int init_data);
tStackNode *push(tStackNode *head, int init_data);
int pop(tStackNode **stack);
void destroy(tStackNode *stack);
tStackNode *get_memory(void);

#endif
