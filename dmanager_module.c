#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
#include "list.h"
#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
int compare_id(const void *a, const void *b);


int main()
{
    struct door doors[DOORS_COUNT];
    
    initialize_doors(doors);
    qsort(doors, DOORS_COUNT, sizeof(struct door),compare_id);
    
        for (int i =0;i< DOORS_COUNT;i++){
        if(doors[i].status==1) doors[i].status=0;
    }
    
    for (int i =0;i< DOORS_COUNT;i++){
        printf("id %d status %d\n", doors[i].id,doors[i].status);
    }


    struct node *node_list = init(doors,DOORS_COUNT);
    
    tNode* p = node_list;
    while (p != NULL){
        printf("id %d status %d\n", p->node_door.id, p->node_door.status);
        p = p->next;
    }


    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors)
{
    srand(time(0)); 
    
    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++)
    {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

int compare_id(const void *a, const void *b) {
    struct door *door_1 = (struct door *)a;
    struct door *door_2 = (struct door *)b;
    return door_1->id - door_2->id;
}