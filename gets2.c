#include <stdio.h>

#define Y 10
#define X 11

int main(void){

char str[Y][X];
int i=0;

while (i < Y  && scanf("%10s", str[i]) == 1)
i++;

for (int k = 0; k<Y;k++)
printf("%s\n", str[k]);

return 0;
}

//  ./a.out  < test.txt
