#include "arbol.h"

void crearArbol(t_arbol *pa)
{
    *pa = NULL;
}
void recorrerPreOrden(const t_arbol *pa, const void *param, Accion accion)
{
    if(!*pa)
        return;

    accion((*pa)->info, param);
    recorrerPreOrden(&(*pa)->izq, param, accion);
    recorrerPreOrden(&(*pa)->der, param, accion);

//    if(*pa)
//    {
//        accion((*pa)->info, param);
//        recorrerPreOrden(&(*pa)->izq, param, accion);
//        recorrerPreOrden(&(*pa)->der, param, accion);
//    }
}
void recorrerInOrden(const t_arbol *pa, const void *param, Accion accion)
{
    if(!*pa)
        return;

    recorrerInOrden(&(*pa)->izq, param, accion);
    accion((*pa)->info, param);
    recorrerInOrden(&(*pa)->der, param, accion);
}
void recorrerPosOrden(const t_arbol *pa, const void *param, Accion accion)
{
    if(!*pa)
        return;

    recorrerPosOrden(&(*pa)->izq, param, accion);
    recorrerPosOrden(&(*pa)->der, param, accion);
    accion((*pa)->info, param);
}

int insertarEnArbol(t_arbol *pa, const void *info, size_t tam_info, Cmp cmp) /// NO INSERTO DUPLICADOS
{
    if(*pa)
    {
        if(cmp(info, (*pa)->info) > 0)
            insertarEnArbol(&(*pa)->der, info, tam_info, cmp);
        else if(cmp(info, (*pa)->info) < 0)
            insertarEnArbol(&(*pa)->izq, info, tam_info, cmp);
    }
    else
    {
        *pa = malloc(sizeof(t_nodo));
        if(!*pa)
            return 0;/// sin mem
        (*pa)->info = malloc(sizeof(tam_info));
        if(!(*pa)->info)
        {
            free(*pa);
            return 0;/// sin mem
        }

        (*pa)->tam_info = tam_info;
        memcpy((*pa)->info, info, tam_info);
        (*pa)->der = (*pa)->izq = NULL;
    }
    return 1;
}

int contarNodos(const t_arbol *pa)
{
    return *pa == NULL ? 0 : (contarNodos(&(*pa)->izq) + contarNodos(&(*pa)->der) + 1);
}

void vaciarArbol(t_arbol *pa)
{
    if(!*pa)
        return;

    vaciarArbol(&(*pa)->izq);
    vaciarArbol(&(*pa)->der);
    free((*pa)->info);
    free(*pa);
    *pa = NULL;
}

int buscarElemento(const t_arbol *pa, void *dato, size_t tam_info, Cmp cmp)
{
    pa = buscarNodo(pa, dato, cmp);
    if(!pa)
        return 0;
    memcpy(dato, (*pa)->info, MINIMO(tam_info, (*pa)->tam_info));
    return 1;
}

int eliminarElemento(t_arbol *pa, void *dato, size_t tam_info, Cmp cmp)
{
    pa = buscarNodo(pa, dato, cmp);
    if(!pa)
        return 0;
    memcpy(dato, (*pa)->info, MINIMO(tam_info, (*pa)->tam_info));
    return eliminarRaiz(pa);
}

int eliminarRaiz(t_arbol *pa)
{
    t_nodo **reemp, *elim;

    if(!*pa)
        return 0;

    free((*pa)->info);

    if(!(*pa)->izq && !(*pa)->der)
    {
        free(*pa);
        *pa = NULL;
        return 1;
    }

    reemp = alturaArbol(&(*pa)->izq) > alturaArbol(&(*pa)->izq) ?
            mayorNodo(&(*pa)->izq) : menorNodo(&(*pa)->der);

    elim = *reemp;

    (*pa)->info = elim->info;
    (*pa)->tam_info = elim->tam_info;

    *reemp = elim->izq ? elim->izq : elim->der;

    free(elim);

    return 1;
}

int alturaArbol(t_arbol *pa)
{
    int hi, hd;

    if(!*pa)
        return 0;

    hi = alturaArbol(&(*pa)->izq);
    hd = alturaArbol(&(*pa)->der);

    return (hi>hd?hi:hd) + 1;
}

t_nodo **mayorNodo(t_arbol *pa)
{
    if(!*pa)
        return 0;

    while((*pa)->der)
        pa = &(*pa)->der;

    return (t_nodo **)pa;
}

t_nodo **menorNodo(t_arbol *pa)
{
    if(!*pa)
        return 0;

    while((*pa)->izq)
        pa = &(*pa)->izq;

    return (t_nodo **)pa;
}

t_nodo **buscarNodo(t_arbol *p, const void *dato, Cmp cmp)
{
    int res;
    if(!*p)
        return NULL;
    res = cmp(dato, (*p)->info);
    if(res>0)
        return buscarNodo(&(*p)->der, dato, cmp);
    if(res<0)
        return buscarNodo(&(*p)->izq, dato, cmp);

    return (t_nodo **)p;
}

int crearArbolIndice(const char* ruta, t_arbol* a, unsigned tam_dato_reg, unsigned tam_clave, Cmp cmp, Accion accion)
{
    char *dato_reg = malloc(tam_dato_reg);
    if(!dato_reg)
        return 0;

    char *idx = malloc(tam_clave+sizeof(unsigned));
    if(!idx)
        return 0;

    if(*a)
        return 0;

    unsigned nro_reg = 0;
    FILE* pf = fopen(ruta, "rb");
    if(!pf)
        return 0;


    while(fread(dato_reg, tam_dato_reg, 1, pf))
    {
        accion(idx, dato_reg);///copia en idx la clave que esta dentro de dato_reg
        memcpy(idx+tam_clave, &nro_reg, sizeof(unsigned));
        insertarEnArbol(a, idx, tam_clave+sizeof(unsigned),cmp);
        nro_reg++;
    }

    fclose(pf);
    free(dato_reg);

    return 1;
}
