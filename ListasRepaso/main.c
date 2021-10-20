#include <stdio.h>
#include <stdlib.h>
#include "Lista_Dinamica.h"

int main()
{

    P_NODO_LISTA lst = NULL;
    lst = insertar(lst,5,1);
    lst = insertar(lst,2,2);
    lst = insertar(lst,3,3);
    lst = insertar(lst,4,4);


    P_NODO_LISTA lst2 = NULL;
    lst2 = insertar(lst2,5,1);
    lst2 = insertar(lst2,4,2);
    lst2 = insertar(lst2,3,3);
    lst2 = insertar(lst2,4,4);

    P_NODO_LISTA lst3 = NULL;
    lst3 = insertar(lst3,1,1);
    lst3 = insertar(lst3,5,2);
    lst3 = insertar(lst3,2,3);
    lst3 = insertar(lst3,3,4);
    lst3 = insertar(lst3,4,5);

    printf("Lista 1: "); imprimir_lista(lst);
    printf("Lista 2: "); imprimir_lista(lst2);
    printf("Lista 3: "); imprimir_lista(lst3);

    int result=0;

    result = sublista(lst2,lst);

    result = sublista(lst3,lst);





    printf("Hello world!\n");
    return 0;
}
