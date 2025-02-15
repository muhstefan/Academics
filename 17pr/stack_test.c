#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

#include "stack_test.h"

int main(void) {
    printf("INIT TEST: first count = 15 ");
    tStackNode* stack = init_test(15);
    printf("PUSH TEST : stack NULL first count = 12 ");
    push_test(NULL, 12);
    printf("PUSH TEST : stack (INIT TEST) count = 10 ");
    stack = push_test(stack, 10);
    printf("PUSH TEST : stack (INIT TEST) count = 9 ");
    stack = push_test(stack, 9);
    printf("POP TEST : stack (INIT TEST) ");
    pop_test(&stack);
    printf("POP TEST : stack (NULL) ");
    pop_test(NULL);
    printf("POP TEST : stack (empty) ");
    tStackNode* stack2 = init(10);
    pop(&stack2);
    pop_test(&stack2);  // FAIL
    printf("DESTROY TEST : stack (NULL) ");
    destroy_test(NULL);
    printf("DESTROY TEST : stack (INIT TEST) ");
    destroy_test(stack);
    destroy(stack2);
    return 0;
}

tStackNode* init_test(int first_count) {
    tStackNode* first = init(first_count);
    printf("SUCCESS\n");
    if (first == NULL) return NULL;
    return first;
}

tStackNode* push_test(tStackNode* node_stack, int add_data) {
    if (node_stack == NULL) {
        printf("FAIL\n");
        return NULL;
    }
    tStackNode* pusht = push(node_stack, add_data);
    if (pusht == NULL) {
        printf("FAIL\n");
        return NULL;
    } else
        printf("SUCCESS\n");
    return pusht;
}
int pop_test(tStackNode** node_stack) {
    if (node_stack == NULL || *node_stack == NULL) {
        printf("FAIL\n");
        return 1;
    }

    int popt = pop(node_stack);

    if (popt == -1) {
        printf("FAIL\n");
        return 1;
    } else {
        printf("SUCCESS\n");
        return 0;
    }
}

int destroy_test(tStackNode* node_stack) {
    if (node_stack == NULL) {
        printf("FAIL\n");
        return 1;
    }
    destroy(node_stack);
    printf("SUCCEESS\n");
    return 0;
}
