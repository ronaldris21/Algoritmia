#include <stdio.h>
#include <stdlib.h>

void matrizDinamica(int dimension){
    int i, **p;
    p = (int **)malloc(sizeof(int*)*dimension);
    for (i = 0; i < dimension ; i++){
    p[i] = (int *)malloc(sizeof(int)*dimension);
    }


     for(i=0; i<dimension;i++)
        for(int j=0; j<dimension;j++)
            p[i][j]=0;


    p[0][0] = 20;
    printf("%d\n",p[0][0]);


    for(i=0; i<dimension;i++)
    {
        for(int j=0; j<dimension;j++)
        {
            printf("%d ",p[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    matrizDinamica(4);
    return;
}
