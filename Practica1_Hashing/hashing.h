#ifndef HASHING_H_INCLUDED
#define HASHING_H_INCLUDED

#define LIBRE -1
#define BORRADO -2

struct myreg{
    int clave;

} myreg;

void inicializar(myreg tabla[], int tam);
void insertar(myreg nuevo, myreg tabla[], int tam);
int buscarPos(int clave, myreg tabla[], int tam);
int borrar(int clave, myreg tabla[], int tam);
double factorCarga(myreg tabla[],int tam);
void imprimir(myreg tabla[], int tam);











#endif // HASHING_H_INCLUDED
