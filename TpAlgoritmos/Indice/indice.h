#ifndef INDICE_H_INCLUDED
#define INDICE_H_INCLUDED

#include "../Arbol/arbol.h"
#include "../Socio/socio.h"
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef struct{
    tArbol arb;
    unsigned tamClave;
    int (*Cmp) (const void* a, const void *b);
}tIndice;

typedef struct
{
    void* clave;
    unsigned nroReg;

}tRegistroIndice;

void indCrear (tIndice* ind, size_t tamClave, int (*cmp)(const void*, const void*));
int indInsertar (tIndice* ind, void *clave, unsigned nroReg);
int indEliminar (tIndice* ind, void *clave, unsigned *nroReg);
int indBuscar (const tIndice* ind, void *clave, unsigned *nroReg);
int indCargar (tIndice* ind, const char* path);
int indGrabar (const tIndice* ind, const char* path);
void indVaciar (tIndice* ind);
int indRecorrer (const tIndice* ind, void (*accion)(const void *, unsigned, void *), void*param);


#endif // INDICE_H_INCLUDED
