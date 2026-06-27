#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MINIMO(x,y) (x<y?x:y)

typedef struct s_nodo
{
    void *info;
    size_t tam_info;
    struct s_nodo *izq, *der;
}t_nodo;

typedef t_nodo* t_arbol;

typedef void (*Accion)(const void *, const void *);
typedef int (*Cmp)(const void *d, const void *);

void crearArbol(t_arbol *pa);
void recorrerPreOrden(const t_arbol *pa, const void *param, Accion accion);
void recorrerInOrden(const t_arbol *pa, const void *param, Accion accion);
void recorrerPosOrden(const t_arbol *pa, const void *param, Accion accion);

int insertarEnArbol(t_arbol *pa, const void *info, size_t tam_info, Cmp cmp);
int contarNodos(const t_arbol *pa);

int buscarElemento(const t_arbol *pa, void *dato, size_t tam_info, Cmp cmp);
int eliminarElemento(t_arbol *pa, void *dato, size_t tam_info, Cmp cmp);

int eliminarRaiz(t_arbol *pa);
int alturaArbol(t_arbol *pa);
t_nodo **mayorNodo(t_arbol *pa);
t_nodo **menorNodo(t_arbol *pa);
t_nodo **buscarNodo(t_arbol *p, const void *dato, Cmp cmp);

void vaciarArbol(t_arbol *pa);

int crearArbolIndice(const char* ruta, t_arbol* a, unsigned tam_dato_reg, unsigned tam_clave, Cmp cmp, Accion accion);

#endif // ARBOL_H_INCLUDED
