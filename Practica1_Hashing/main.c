#include <stdio.h>
#include <stdlib.h>
#include "hashing.h"


int main()
{
    int tam = 2*2*2;
    myreg tabla[tam];

    inicializar(tabla,tam);

    imprimir(tabla,tam);
    insertar(25,tabla,tam);imprimir(tabla,tam);
    insertar(234,tabla,tam);imprimir(tabla,tam);
    insertar(2435,tabla,tam);imprimir(tabla,tam);
    insertar(234,tabla,tam);imprimir(tabla,tam);






    scanf("%d",&tam);
    printf("Hello world!\n");
    return 0;
}
