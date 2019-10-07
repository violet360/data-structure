#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;
    FILE *fptr;
    fptr = fopen("C:\\Users\\LENOVO\\Desktopt\\text.txt","r+");
    fscanf(fptr,"%d", &num);
    printf("%d", num);
    fclose(fptr);
    return 0;
}
