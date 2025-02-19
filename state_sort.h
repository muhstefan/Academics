#ifndef STATE_SORT_H
#define STATE_SORT_H
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
} DoorState;

void merge_files(int num_files, const char *output_filename);
int menu(int decision, char *filename);
int input(int *n);  // проверка на цифру ввода?
FILE *read_file(char *filename);
int input_name(char *filename);
int write_file(char *filename);
int check_exist(char *filename);
int sort_part(DoorState *records, int recordCount);
int compare(const void *a, const void *b);
int show(DoorState *records, int recordCount);

#endif  // STATE_SORT_H