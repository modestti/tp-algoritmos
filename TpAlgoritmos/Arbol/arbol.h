#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MINIMO(x,y) (x<y?x:y)

typedef struct sNodo
{
    void *info;
    size_t tamInfo;
    struct sNodo *izq, *der;
}tNodo;

typedef tNodo* tArbol;

typedef void (*Accion)(const void *, const void *);
typedef int (*Cmp)(const void *d, const void *);

void crearArbol(tArbol *pa);
void recorrerPreOrden(const tArbol *pa, const void *param, Accion accion);
void recorrerInOrden(const tArbol *pa, const void *param, Accion accion);
void recorrerPosOrden(const tArbol *pa, const void *param, Accion accion);

int insertarEnArbol(tArbol *pa, const void *info, size_t tamInfo, Cmp cmp);
int contarNodos(const tArbol *pa);

int buscarElemento(const tArbol *pa, void *dato, size_t tamInfo, Cmp cmp);
int eliminarElemento(tArbol *pa, void *dato, size_t tamInfo, Cmp cmp);

int eliminarRaiz(tArbol *pa);
int alturaArbol(tArbol *pa);
tNodo **mayorNodo(tArbol *pa);
tNodo **menorNodo(tArbol *pa);
tNodo **buscarNodo(const tArbol *p, const void *dato, Cmp cmp);

void vaciarArbol(tArbol *pa);

int crearArbolIndice(const char* ruta, tArbol* a, unsigned tamDatoReg, unsigned tamClave, Cmp cmp, Accion accion);

#endif // ARBOL_H_INCLUDED
