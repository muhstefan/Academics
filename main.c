#include <stdio.h>
#include <stdlib.h>

#define lines 9
#define cells 9

int input(int *n);
void move(int **matrix);

void several_parts() {
    int **diferent_lines = (int **)malloc(sizeof(int *) * lines);
    for (int i_1 = 0; i_1 < lines; i_1++) diferent_lines[i_1] = (int *)malloc(sizeof(int) * cells);

    for (int j_1 = 0; j_1 < lines; j_1++)
        for (int k_1 = 0; k_1 < cells; k_1++) diferent_lines[j_1][k_1] = k_1 + j_1;

    for (int j_2 = 0; j_2 < lines; j_2++) free(diferent_lines[j_2]);

    free(diferent_lines);
}

int **two_parts() {
    int **diferent_lines = (int **)malloc(sizeof(int *) * lines);
    int *p = (int *)malloc(sizeof(int) * lines * cells);
    if (diferent_lines == NULL) return NULL;
    if (p == NULL) return NULL;
    for (int i = 0; i < lines; i++) diferent_lines[i] = p + i * cells;

    for (int j_1 = 0; j_1 < lines; j_1++)
        for (int k_1 = 0; k_1 < cells; k_1++) diferent_lines[j_1][k_1] = 0;

    return diferent_lines;
}

void output(int **matrix) {
    for (int j_2 = 0; j_2 < lines; j_2++) {
        for (int k_2 = 0; k_2 < cells; k_2++) printf("%d ", matrix[j_2][k_2]);
        printf("\n");
    }
}

void one_piece() {
    int **diferent_lines = (int **)malloc(sizeof(int *) * lines);
    for (int i_1 = 0; i_1 < lines; i_1++) diferent_lines[i_1] = (int *)malloc(sizeof(int) * cells);

    for (int j_1 = 0; j_1 < lines; j_1++)
        for (int k_1 = 0; k_1 < cells; k_1++) diferent_lines[j_1][k_1] = k_1 + j_1;

    for (int j_2 = 0; j_2 < lines; j_2++) free(diferent_lines[j_2]);

    free(diferent_lines);
}

int main(void) {
    int **matrix = two_parts();
    if (matrix == NULL) {
        puts("ETO FIASKO");
        return 1;
    }
    move(matrix);
    output(matrix);
    puts("\n");

    return 0;
}

int input(int *n) {
    char c = '-';
    if (scanf("%d%c", n, &c) != 2 || (c != ' ' && c != '\n')) return 1;
    return 0;
}

void move(int **matrix) {
    int y_dir[] = {1, 0, -1, 0};
    int x_dir[] = {0, 1, 0, -1};
    int dir = 0;

    int y = 0, x = 0;
    int dig = 0;

    int top = 0, bottom = lines - 1;  // Границы по строкам
    int left = 0, right = cells - 1;  // Границы по столбцам

    while (dig <= lines * cells - 1) {
        matrix[y][x] = dig * dig;
        dig++;

        y += y_dir[dir];
        x += x_dir[dir];

        // Если вышли за границы, меняем направление
        if (x > right) {
            x = right;
            y--;
            dir = (dir + 1) % 4;
            bottom--;
        } else if (y > bottom) {
            y = bottom;
            x++;
            dir = (dir + 1) % 4;
            left++;
        } else if (x < left) {
            x = left;
            y++;
            dir = (dir + 1) % 4;
            top++;
        } else if (y < top) {
            y = top;
            x--;
            dir = (dir + 1) % 4;
            right--;
        }
    }
}
