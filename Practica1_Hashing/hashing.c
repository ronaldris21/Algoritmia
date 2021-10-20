#include "hashing.h"
#include <stdio.h>
#include <stdlib.h>


void inicializar(myreg tabla[], int tam)
{
    for(int i=0;i<tam;i++)
        tabla[i].clave = LIBRE;
}
int H(int k, int tam)
{
    return k%tam;
}

int H_lineal(int k, int tam, int i)
{
    return (k+i)%tam;
}

void insertar(int nuevo, myreg tabla[], int tam)
{
    int pos = H(nuevo,tam);
    int cantColisiones=0;

    if(tabla[pos].clave == LIBRE  || tabla[pos].clave == BORRADO)
        tabla[pos].clave = nuevo;
    else
    {
        ///COLISIÓN
        cantColisiones++;
        for(int i=1;i<tam;i++)
        {
            pos = H_lineal(nuevo,tam,i);
            if(tabla[pos].clave == LIBRE  || tabla[pos].clave == BORRADO)
            {
                tabla[pos].clave = nuevo;
                break;
            }
            else
            {
                cantColisiones++;
            }
        }
    }
}


int buscarPos(int clave, myreg tabla[], int tam)
{
    int pos = H(clave,tam);
    if(tabla[pos].clave == LIBRE)
        return LIBRE;
    if(tabla[pos].clave == BORRADO)
    {
        ///Sigo buscando en las colisiones
        for(int i=1;i<tam;i++)
        {
            pos = H_lineal(clave,tam,i);
            if(tabla[pos].clave == LIBRE)
                return LIBRE;
            if(tabla[pos].clave !=BORRADO)
                return pos;
        }
    }
    else
    {
        return pos;
    }
    return LIBRE;
}


int borrar(int clave, myreg tabla[], int tam)
{
    int pos = buscarPos(clave,tabla,tam);
    if(pos == LIBRE)
        return 0; ///Que no lo borro
    else
    {
        tabla[pos].clave = BORRADO;
        return 1;
    }
}


double factorCarga(myreg tabla[],int tam)
{
    int cantLibres = 0;
    for(int i=0; i<tam;i++)
    {
        if(tabla[i].clave == LIBRE)
            cantLibres++;
    }
    int cantUsos = tam - cantLibres;
    return 1 / (1 - cantUsos/tam);

}


void imprimir(myreg tabla[], int tam)
{
    for(int i=0; i<tam;i++)
    {
        if(tabla[i].clave == LIBRE)
            printf("%d: \tLIBRE\n",i);
        else
            printf("%d: \t%d\n",i,tabla[i].clave);
    }
     printf("\n\n");
}




