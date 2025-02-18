#include <ctype.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>

int menu(int decision, char *filename);
int input(int *n);  // проверка на цифру ввода?
int read_file(char *filename);
int input_name(char *filename);
int write_file(char *filename);
int open_dir(int sdvig);
void cesar(char *input_name, int sdvig);
int check_exist(char *filename);
int clear(char *filename);

int main(void) {
    int decision = 0;
    int loop = 1;

    char filename[256] = "";
    while (loop) {
        if (input(&decision) != 0) {
            printf("n/a\n");
            continue;
        }  // 2 n/a выводит
        loop = menu(decision, filename);
        if (loop == -10) {
            printf("n/a");
            return 1;
        }
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
        input(&sdvig);
        open_dir(sdvig);

    } else if (decision == -1)
        return 0;
    else
        printf("\nn/a");
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

int read_file(char *filename) {
    FILE *my_File = fopen(filename, "r");
    if (my_File == NULL) {
        printf("\nn/a");
        return 1;
    }
    int ch = fgetc(my_File);  // проверка на пустой файл
    if (ch == EOF) {
        printf("\nn/a");
        fclose(my_File);
        return 0;
    }
    printf("\n");
    printf("%c", ch);
    while ((ch = fgetc(my_File)) != EOF) {
        printf("%c", ch);
    }
    fclose(my_File);
    return 0;
}

int input_name(char *filename) {
    char ch = '0';
    if (scanf("%255s%c", filename, &ch) != 2 || (ch != ' ' && ch != '\n')) return 1;

    return 0;
}

int write_file(char *filename) {
    char buffer;

    FILE *my_File = fopen(filename, "a");
    if (my_File == NULL) return 1;
    while ((buffer = getchar()) != '\n') fputc(buffer, my_File);

    fclose(my_File);

    return 0;
}

int open_dir(int sdvig) {
    char dir_path[256] = "ai_modules";
    char full[512] = "";
    DIR *dir;
    struct dirent *entry;
    dir = opendir(dir_path);
    if (!dir) {
        perror("n/a");
        return 1;
    };

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            snprintf(full, sizeof(full), "%s/%s", dir_path, entry->d_name);
            int lenght = strlen(entry->d_name);
            if (entry->d_name[lenght - 1] == 'c')
                cesar(full, sdvig);
            else if (entry->d_name[lenght - 1] == 'h')
                clear(full);
        }
    };

    closedir(dir);

    return 0;
}

void cesar(char *input_name, int sdvig) {
    FILE *file = fopen(input_name, "r+");
    if (file == NULL) {
        return;
    }
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (isalpha(ch)) {  // если буква
            fseek(file, ftell(file) - 1, SEEK_SET);
            fputc(ch + sdvig, file);
        }
    }

    fclose(file);
    printf("Успех СДВГинули файл :%s\n", input_name);
}
// открыть на запись и все
int check_exist(char *filename) {
    FILE *my_File = fopen(filename, "r");
    if (my_File == NULL) return 1;
    fclose(my_File);
    return 0;
}

int clear(char *filename) {
    FILE *my_File = fopen(filename, "w");
    if (my_File == NULL) return 1;
    fclose(my_File);
    return 0;
}
