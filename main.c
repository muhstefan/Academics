#include <stdio.h>
#include <stdlib.h>

int input(int *n);

void several_parts(){
   
    int lines = 4;
    int cells = 5;

    int ** diferent_lines = (int**)malloc(sizeof(int*)* lines);
    for(int i_1 = 0; i_1 < lines;i_1++)
    diferent_lines[i_1] = (int*)malloc(sizeof(int)*cells);

    for(int j_1 = 0; j_1 < lines;j_1++)
    for(int k_1 = 0; k_1 < cells;k_1++)
    diferent_lines[j_1][k_1] = k_1 + j_1;

    for(int j_2 = 0; j_2 < lines;j_2++)
    free(diferent_lines[j_2]);

    free(diferent_lines); 
}

void two_parts(){
   
    int lines = 4;
    int cells = 5;

    int ** diferent_lines = (int**)malloc(sizeof(int*)* lines);
    for(int i_1 = 0; i_1 < lines;i_1++)
    diferent_lines[i_1] = (int*)malloc(sizeof(int)*cells);

    for(int j_1 = 0; j_1 < lines;j_1++)
    for(int k_1 = 0; k_1 < cells;k_1++)
    diferent_lines[j_1][k_1] = k_1 + j_1;

    for(int j_2 = 0; j_2 < lines;j_2++)
    free(diferent_lines[j_2]);

    free(diferent_lines); 
}

void one_piece(){
   
    int lines = 4;
    int cells = 5;

    int ** diferent_lines = (int**)malloc(sizeof(int*)* lines);
    for(int i_1 = 0; i_1 < lines;i_1++)
    diferent_lines[i_1] = (int*)malloc(sizeof(int)*cells);

    for(int j_1 = 0; j_1 < lines;j_1++)
    for(int k_1 = 0; k_1 < cells;k_1++)
    diferent_lines[j_1][k_1] = k_1 + j_1;

    for(int j_2 = 0; j_2 < lines;j_2++)
    free(diferent_lines[j_2]);

    free(diferent_lines); 
}


int main(void){

    int n;
    for (int i =0; i < 10 ; i ++)
    input(&n);

return 0;
}


int input(int *n){
    char c ='-';
    if (scanf("%d%c", n, &c) != 2 || (c != ' ' && c != '\n')) return 1;
    return 0;
}


matrix fillin(){

    while(size !=0){

        ryad(matrix);
        flag = !flag
        //size -=1;
    }
}

int ryad(matrix,size,flag){
    static int k = 0;
    static int dig =0;
    int i =k
    if(flag ==0)
    {
        for(i;i <size;i++)
            {
            matrix[i][k];
            dig++;
            }
    }
    

    
    }
    else { 
        for(i;i <size;i++)
            {
            matrix[k][i];
            dig++;
            }
        }
    k=i;
    

    
}