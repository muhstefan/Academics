#ifndef STACK_TEST_H
#define STACK_TEST_H

#include "stack.h"

tStackNode* init_test(int first_count);
tStackNode* push_test(tStackNode* node_stack, int add_data);
int pop_test(tStackNode** node_stack);
int destroy_test(tStackNode* node_stack);

#endif
