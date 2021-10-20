#include "Lista_Dinamica.h"

int es_vacia (P_NODO_LISTA lista){
	if(lista==NULL)
        return 1;
    else
        return 0;
}

P_NODO_LISTA insertar(P_NODO_LISTA lst, int valor, int pos){ // devuelve P_NODO_LISTA

    P_NODO_LISTA laux, lsgte;
    int i;

    if(pos < 1 ) {
           printf("ERROR, fuera de posicion\n");
           return lst;
     }
    //Insertamos al principio
    if ( pos == 1 || es_vacia(lst)){
        laux = (P_NODO_LISTA)malloc(sizeof(NODO_LISTA));
        laux->valor = valor;
        laux->anterior = NULL;  // Soy el primero, pongo el anterior a NULL
        laux->siguiente = lst;  // Y el siguiente lo apunto a lst
        if(!es_vacia(lst))
            lst->anterior = laux; // Si no es vacia apuntamos lst->anterior al primero

        return(laux);
    }

    // resto de posiciones
    for (i=1, laux=lst;(i<pos-1)&&(laux!=NULL);i++)
        laux = laux->siguiente;


    if( laux != NULL) {
        lsgte = laux->siguiente;
        laux->siguiente = (P_NODO_LISTA)malloc(sizeof(NODO_LISTA));
        laux->siguiente->valor = valor;
        laux->siguiente->siguiente = lsgte; // Apuntamos al siguiente
        laux->siguiente->anterior = laux;   // Apuntamos hacia atras

		if(lsgte != NULL) //no es el ultimo cuando inserto
            lsgte->anterior = laux->siguiente;
    } //fin del if
    else  printf("ERROR, fuera de posicion\n");

    return(lst);
}


P_NODO_LISTA borrar(P_NODO_LISTA lst, int pos, int *valor){

    P_NODO_LISTA laux;
    int i;

    //Si la posicion esta fuera de rango o la lista es vacia nose hace nada. Devolvemos la lista tal cual.
    if ((pos < 1) || (es_vacia(lst))){
        printf("ERROR, Lista vacia o posicion no valida\n");
        *valor = -1;
        return lst;

    }

    // Primera posicion
    if (pos == 1){
        laux = lst->siguiente;
        *valor = lst->valor;
        free(lst);
        if(laux != NULL)
            laux->anterior = NULL;
        return (laux);
    }

    // Resto de posiciones
    for (i=1, laux=lst; (i<pos)&&(laux->siguiente != NULL); i++)
        laux = laux->siguiente;

    //Si no hemos llegado al último nodo, eliminamos y
	//actualizamos las referencias del nodo anterior y posterior del eliminado
    if(laux->siguiente != NULL) {
		laux->anterior->siguiente = laux->siguiente;
		laux->siguiente->anterior = laux->anterior;
		*valor = laux->valor;
		free(laux);
    }
    else if (pos==i){ //es el ultimo de la lista
        laux->anterior->siguiente=laux->siguiente; //null
        *valor = laux->valor;
        free(laux);
    }
    else {
       	*valor = -1;
   		printf("ERROR, fuera de posicion\n");
	}

    return(lst);

}

P_NODO_LISTA buscar(P_NODO_LISTA lst, int valor){

    P_NODO_LISTA laux;
    for(laux=lst; laux!=NULL;laux=laux->siguiente)
        if(laux->valor == valor) break;

    return(laux);
}

void imprimir_lista (P_NODO_LISTA lst){
    P_NODO_LISTA p;
    p=lst;

    while(p!= NULL){
        printf("%d ", p->valor);
        p=p->siguiente;
    }
    printf("\n");
}


int sublista(P_NODO_LISTA lst2,P_NODO_LISTA lst)
{
    P_NODO_LISTA paux = NULL;
    P_NODO_LISTA paux2 = NULL;

    int cant_l1, cant_l2;

    for(paux = lst , cant_l1 = 0; paux!=NULL; paux = paux->siguiente)
        cant_l1++;
    for(paux = lst2 , cant_l2 = 0; paux!=NULL; paux = paux->siguiente)
        cant_l2++;

    if(cant_l2>cant_l1)
    {
        printf("No son sublistas\n");
        return 0; //No es sublista
    }


        ///El primero debe de coincidir y luego todos los demas
    for(paux = lst, paux2= lst2 ; paux!=NULL  && paux2!=NULL; paux2 = paux2->siguiente)
    {
        if(paux2->valor== paux->valor)
        {
            paux2=paux2->siguiente;
            paux=paux->siguiente;
        }

        if(paux->siguiente==NULL)
        {

            printf("\n");
            imprimir_lista(lst2);
            imprimir_lista(lst);
            printf("SON SUBLISTA\n");
            return 1;  ///Ha encontrado a TODOS
        }


        ///Recorrio la lista y no lo logro
        if(paux2->siguiente ==NULL)
        {
            printf("No son sublistas\n");
            return 0;
        }

    }

    printf("No son sublistas\n");

    return 0;


}
