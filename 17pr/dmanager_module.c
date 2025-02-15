#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"
#include "list.h"
#include "list_test.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door *doors);
int compare_id(const void *a, const void *b);

int main(void) {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);

    qsort(doors, DOORS_COUNT, sizeof(struct door), compare_id);  // отсортировать по id

    for (int i = 0; i < DOORS_COUNT; i++) {  // закрыть все мои дверочки
        if (doors[i].status == 1) doors[i].status = 0;
    }

#ifdef DOORS
    for (int i = 0; i < DOORS_COUNT; i++) {  // давайте взглянем на это чудо
        if (i < DOORS_COUNT - 1)
            printf("%d, %d\n", doors[i].id, doors[i].status);
        else
            printf("%d, %d", doors[i].id, doors[i].status);
    }
    printf("\n");
#endif

#ifdef TESTS
    tNode *node_list = init(doors, DOORS_COUNT);
    struct door door_1 = {16, 0};
    struct door *door_1_p = &door_1;
    struct door *door_2 = NULL;
    printf("ADD TEST:\n");
    printf("node_list doors 15 + door witch id 16 und status Close. We put it in 3 place TEST:");
    add_door_test(node_list, door_1_p, 3);
    printf("node_list doors 16 + door NULL TEST:");
    add_door_test(node_list, door_2, 3);
    printf("node_list doors 16 + door witch id 16 und status Close We put it in 18 place TEST:");
    add_door_test(node_list, door_1_p, 18);
    printf("node_list NULL + door witch id 16 und status Close We put it in 1 place TEST:");
    add_door_test(NULL, door_1_p, 1);
    printf("REMOVE TEST:\n");
    printf("node_list 16 -  3st doorTEST:");
    remove_door_test(node_list, 3);
    printf("node_list NULL -  3st doorTEST:");
    remove_door_test(NULL, 3);
    printf("node_list 16 -  20 st doorTEST:");
    remove_door_test(node_list, 20);
    destroy(node_list);
#endif

    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door *doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

int compare_id(const void *a, const void *b) {
    struct door *door_1 = (struct door *)a;
    struct door *door_2 = (struct door *)b;
    return door_1->id - door_2->id;
}
