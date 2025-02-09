#include <stdio.h>

#define Y 10
#define X 10

int main(void){

char str[Y][X];

FILE * file = fopen("test.txt", "r");
if(file == NULL) return 1;

int i=0;

while(!feof(file)){

fgets(str[i++],sizeof(str),file);
}

for (int k = 0; i<Y;k++)
    {
    for(int b=0;b< X;b++)
    printf("%c", str[i][b]);
    printf("\n");
    }
    
fclose(file);


return 0;
}


