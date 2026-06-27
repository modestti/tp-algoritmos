#ifndef INDICE_H_INCLUDED
#define INDICE_H_INCLUDED

#include "../Arbol/arbol.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    void* clave;
    unsigned nroReg;

}tIndice;

void indCrear (tIndice* ind, size_t tamClave, int (*cmp)(const void*, const void*));
int indInsertar (tIndice* ind, void *clave, unsigned nroReg);
int indEliminar (tIndice* ind, void *clave, unsigned *nroReg);
int indBuscar (const tIndice* ind, void *clave, unsigned *nroReg);
int indCargar (tIndice* ind, const char* path);
int indGrabar (const tIndice* ind, const char* path);
void indVaciar (tIndice* ind);
int indRecorrer (const tIndice* ind, void (*accion)(const void *, unsigned, void *), void*param);


#endif // INDICE_H_INCLUDED
