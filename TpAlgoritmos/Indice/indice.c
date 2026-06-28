#include "indice.h"
void indCrear (tIndice* ind, size_t tamClave, int (*cmp)(const void*, const void*))
{
    crearArbol(&(ind->arb));
    ind->tamClave=tamClave;
    ind->Cmp= cmp;
}
int indInsertar (tIndice* ind, void *clave, unsigned nroReg)
{
    return OK;
}
int indEliminar (tIndice* ind, void *clave, unsigned *nroReg)
{
    return OK;
}

int indBuscar (const tIndice* ind, void *clave, unsigned *nroReg)
{
    return OK;
}

int indCargar (tIndice* ind, const char* path)
{
     return OK;
}

int indGrabar (const tIndice* ind, const char* path)
{
     return OK;
}

void indVaciar (tIndice* ind)
{

}

int indRecorrer (const tIndice* ind, void (*accion)(const void *, unsigned, void *), void*param)
{
     return OK;
}
