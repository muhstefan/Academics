#include "state_sort.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int decision = 0;
    int loop = 1;
    char filename[256] = "";

    while (loop) {
        if (input(&decision) != 0) {
            printf("n/a\n");
            continue;
        }

        loop = menu(decision, filename);
    }
    return 0;
}

int menu(int decision, char *filename) {  // в зависимости от выбранной опции
    if (decision == 1)                    // читаем если не получилось ошибка
    {
        if (input_name(filename) != 0) {
            printf("n/a\n");
            return 1;
        }
        read_file(filename);

    } else if (decision == 2) {
        if (check_exist(filename) != 0) {
            while (getchar() != '\n');  // чистим буффер
            printf("\nn/a");
            return 1;
        }
        write_file(filename);
        read_file(filename);

    } else if (decision == 3) {
        int sdvig = 0;
        if (input(&sdvig) != 0) {
            printf("n/a\n");
            return 1;
        }

    } else if (decision == -1) {
        return 0;
    } else {
        printf("\nn/a");
    }
    return 1;
}

int input(int *decision) {
    char ch = '0';
    if (scanf("%d%c", decision, &ch) != 2 || (ch != ' ' && ch != '\n')) {
        while (getchar() != '\n');
        return 1;
    }

    return 0;
}

void read_record(FILE *file, DoorState *record, long position) {  // cчитываем структурами
    fseek(file, position * sizeof(DoorState), SEEK_SET);
    fread(record, sizeof(DoorState), 1, file);
}

void sort_and_write_to_temp(FILE *file, long start, long end, int temp_index) {
    long count = end - start + 1;
    DoorState *records = malloc(count * sizeof(DoorState));

    // Чтение записей в память
    for (long i = 0; i < count; i++) {
        read_record(file, &records[i], start + i);
    }

    // Сортировка записей в памяти
    qsort(records, count, sizeof(DoorState), compare);

    // Запись отсортированных записей во временный файл
    char temp_filename[20];
    sprintf(temp_filename, "temp_%d", temp_index);  // Создаем имя временного файла

    FILE *temp_file = fopen(temp_filename, "wb");
    if (!temp_file) {
        perror("Ошибка открытия временного файла");
        free(records);
        return;
    }

    fwrite(records, sizeof(DoorState), count, temp_file);
    fclose(temp_file);
    free(records);
}

FILE *read_file(char *filename) {
    FILE *my_File = fopen(filename, "rb");
    if (my_File == NULL) {
        printf("\nn/a");
        return NULL;
    }

    return my_File;
}

int show(DoorState *records, int recordCount) {
    for (int i = 0; i < recordCount; i++) {
        printf("%d-%d-%d-%d-%d-%d-%d-%d\n", records[i].year, records[i].month, records[i].day,
               records[i].hour, records[i].minute, records[i].second, records[i].status, records[i].code);
    }
}

int sort_part(DoorState *records, int recordCount) {
    qsort(records, recordCount, sizeof(DoorState), compare);
}

int input_name(char *filename) {
    char ch = '0';
    if (scanf("%255s%c", filename, &ch) != 2 || (ch != ' ' && ch != '\n')) return 1;

    return 0;
}

void merge_files(int num_files, const char *output_filename) {
    FILE **temp_files = malloc(num_files * sizeof(FILE *));
    for (int i = 0; i < num_files; i++) {
        char temp_filename[20];
        sprintf(temp_filename, "temp_%d", i);
        temp_files[i] = fopen(temp_filename, "rb");
    }

    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        perror("Ошибка открытия выходного файла");
        return;
    }

    DoorState *buffers = malloc(num_files * sizeof(DoorState));
    int *eof_flags = calloc(num_files, sizeof(int));

    // Инициализация буферов
    for (int i = 0; i < num_files; i++) {
        if (fread(&buffers[i], sizeof(DoorState), 1, temp_files[i]) != 1) {
            eof_flags[i] = 1;  // Установить флаг конца файла
        }
    }

    while (1) {
        int min_index = -1;
        for (int i = 0; i < num_files; i++) {
            if (!eof_flags[i] && (min_index == -1 || compare(&buffers[i], &buffers[min_index]) < 0)) {
                min_index = i;
            }
        }

        if (min_index == -1) break;  // Все файлы прочитаны

        fwrite(&buffers[min_index], sizeof(DoorState), 1, output_file);

        if (fread(&buffers[min_index], sizeof(DoorState), 1, temp_files[min_index]) != 1) {
            eof_flags[min_index] = 1;  // Установить флаг конца файла
        }
    }

    // Закрытие файлов
    for (int i = 0; i < num_files; i++) {
        fclose(temp_files[i]);
        remove(temp_files[i]);  // Удаление временных файлов
    }
    free(temp_files);
    free(buffers);
    free(eof_flags);
    fclose(output_file);
}

int compare(const void *a, const void *b) {
    DoorState *stateA = (DoorState *)a;
    DoorState *stateB = (DoorState *)b;

    if (stateA->year != stateB->year) {
        return stateA->year - stateB->year;
    }
    if (stateA->month != stateB->month) {
        return stateA->month - stateB->month;
    }
    if (stateA->day != stateB->day) {
        return stateA->day - stateB->day;
    }
    if (stateA->hour != stateB->hour) {
        return stateA->hour - stateB->hour;
    }
    if (stateA->minute != stateB->minute) {
        return stateA->minute - stateB->minute;
    }
    return stateA->second - stateB->second;  // вычитаем т.к это позволяет определить порядок
}

// int check_exist(char *filename) {
//     FILE *my_File = fopen(filename, "rb");
//     if (my_File == NULL) return 1;
//     fclose(my_File);
//     return 0;
// }

// int clear(char *filename) {
//     FILE *my_File = fopen(filename, "wb");
//     if (my_File == NULL) return 1;
//     fclose(my_File);
//     return 0;
// }
// int write_file(char *filename) {
//     char buffer;

//     FILE *my_File = fopen(filename, "ab");
//     if (my_File == NULL) return 1;
//     while ((buffer = getchar()) != '\n') fputc(buffer, my_File);

//     fclose(my_File);

//     return 0;
// }