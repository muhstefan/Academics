#include <stdio.h>
#include <stdlib.h>

#define lines 3
#define cells 3

void ryad(int **matrix, int flag);
void matrix_fillin(int **matrix);
int input(int *n);

void several_parts()
{

    int **diferent_lines = (int **)malloc(sizeof(int *) * lines);
    for (int i_1 = 0; i_1 < lines; i_1++)
        diferent_lines[i_1] = (int *)malloc(sizeof(int) * cells);

    for (int j_1 = 0; j_1 < lines; j_1++)
        for (int k_1 = 0; k_1 < cells; k_1++)
            diferent_lines[j_1][k_1] = k_1 + j_1;

    for (int j_2 = 0; j_2 < lines; j_2++)
        free(diferent_lines[j_2]);

    free(diferent_lines);
}

int **two_parts()
{

    int **diferent_lines = (int **)malloc(sizeof(int *) * lines);
    int *p = (int *)malloc(sizeof(int) * lines * cells);
    if (diferent_lines == NULL)
        return NULL;
    if (p == NULL)
        return NULL;
    for (int i = 0; i < lines; i++)
        diferent_lines[i] = p + i * cells;

    for (int j_1 = 0; j_1 < lines; j_1++)
        for (int k_1 = 0; k_1 < cells; k_1++)
            diferent_lines[j_1][k_1] = 0;

    return diferent_lines;
}

void output(int **matrix)
{

    for (int j_2 = 0; j_2 < lines; j_2++)
    {
        for (int k_2 = 0; k_2 < cells; k_2++)
            printf("%d ", matrix[j_2][k_2]);
        printf("\n");
    }
}

void one_piece()
{

    int **diferent_lines = (int **)malloc(sizeof(int *) * lines);
    for (int i_1 = 0; i_1 < lines; i_1++)
        diferent_lines[i_1] = (int *)malloc(sizeof(int) * cells);

    for (int j_1 = 0; j_1 < lines; j_1++)
        for (int k_1 = 0; k_1 < cells; k_1++)
            diferent_lines[j_1][k_1] = k_1 + j_1;

    for (int j_2 = 0; j_2 < lines; j_2++)
        free(diferent_lines[j_2]);

    free(diferent_lines);
}

int main(void)
{

    int **matrix = two_parts();
    if (matrix == NULL)
    {
        puts("ETO FIASKO");
        return 1;
    }
    matrix_fillin(matrix);
    output(matrix);
    puts("\n");

    return 0;
}

int input(int *n)
{
    char c = '-';
    if (scanf("%d%c", n, &c) != 2 || (c != ' ' && c != '\n'))
        return 1;
    return 0;
}

void matrix_fillin(int **matrix)
{

    int flag = 0;
    int size = cells;
    while (size != 0)
    {

        ryad(matrix, flag);
        flag = !flag;
    }
}

void ryad(int **matrix, int flag)
{
    static int size = cells;
    static int k = 0;
    static int dig = 0;
    static int second_stepline = 0;
    static int direction_x = 0;
    static int direction_y = 0;

    int i = 0;
    if (flag == 0)
    {
        if (direction_x == 0)
        {
            for (i = second_stepline; i < size; i++) // команда которая выполняется перед циклом ;   ; команда которая выполняется после цикла
            {
                matrix[i][k] = dig * dig;
                dig++;
                direction_x = !direction_x;
            }
        }
        else
        {
            for (i = second_stepline; i >= 0; i--) // команда которая выполняется перед циклом ;   ; команда которая выполняется после цикла
            {
                matrix[i][k] = dig * dig;
                dig++;
                direction_x = !direction_x;
            }
        }
        else
        {
            for (i = second_stepline; i < size; i++)
            {
                matrix[k][i] = dig * dig;
                dig++;
                direction_y = !direction_y;
            }
            size--;
        }
        k = i - 1;
        second_stepline = 1;
    }

    // alt shift F можно сделать автоформатирование по клику.
    // узнать есть ли какой то дебаггер на экзе . посмотреть есть ли какой на учебных есть ли дебаггер