#include "arbol.h"

void crearArbol(tArbol *pa)
{
    *pa = NULL;
}
void recorrerPreOrden(const tArbol *pa, const void *param, Accion accion)
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
void recorrerInOrden(const tArbol *pa, const void *param, Accion accion)
{
    if(!*pa)
        return;

    recorrerInOrden(&(*pa)->izq, param, accion);
    accion((*pa)->info, param);
    recorrerInOrden(&(*pa)->der, param, accion);
}
void recorrerPosOrden(const tArbol *pa, const void *param, Accion accion)
{
    if(!*pa)
        return;

    recorrerPosOrden(&(*pa)->izq, param, accion);
    recorrerPosOrden(&(*pa)->der, param, accion);
    accion((*pa)->info, param);
}

int insertarEnArbol(tArbol *pa, const void *info, size_t tamInfo, Cmp cmp) /// NO INSERTO DUPLICADOS
{
    if(*pa)
    {
        if(cmp(info, (*pa)->info) > 0)
            insertarEnArbol(&(*pa)->der, info, tamInfo, cmp);
        else if(cmp(info, (*pa)->info) < 0)
            insertarEnArbol(&(*pa)->izq, info, tamInfo, cmp);
    }
    else
    {
        *pa = malloc(sizeof(tNodo));
        if(!*pa)
            return 0;/// sin mem
        (*pa)->info = malloc(sizeof(tamInfo));
        if(!(*pa)->info)
        {
            free(*pa);
            return 0;/// sin mem
        }

        (*pa)->tamInfo = tamInfo;
        memcpy((*pa)->info, info, tamInfo);
        (*pa)->der = (*pa)->izq = NULL;
    }
    return 1;
}

int contarNodos(const tArbol *pa)
{
    return *pa == NULL ? 0 : (contarNodos(&(*pa)->izq) + contarNodos(&(*pa)->der) + 1);
}

void vaciarArbol(tArbol *pa)
{
    if(!*pa)
        return;

    vaciarArbol(&(*pa)->izq);
    vaciarArbol(&(*pa)->der);
    free((*pa)->info);
    free(*pa);
    *pa = NULL;
}

int buscarElemento(const tArbol *pa, void *dato, size_t tamInfo, Cmp cmp)
{
    pa = buscarNodo(pa, dato, cmp);
    if(!pa)
        return 0;
    memcpy(dato, (*pa)->info, MINIMO(tamInfo, (*pa)->tamInfo));
    return 1;
}

int eliminarElemento(tArbol *pa, void *dato, size_t tamInfo, Cmp cmp)
{
    pa = buscarNodo(pa, dato, cmp);
    if(!pa)
        return 0;
    memcpy(dato, (*pa)->info, MINIMO(tamInfo, (*pa)->tamInfo));
    return eliminarRaiz(pa);
}

int eliminarRaiz(tArbol *pa)
{
    tNodo **reemp, *elim;

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
    (*pa)->tamInfo = elim->tamInfo;

    *reemp = elim->izq ? elim->izq : elim->der;

    free(elim);

    return 1;
}

int alturaArbol(tArbol *pa)
{
    int hi, hd;

    if(!*pa)
        return 0;

    hi = alturaArbol(&(*pa)->izq);
    hd = alturaArbol(&(*pa)->der);

    return (hi>hd?hi:hd) + 1;
}

tNodo **mayorNodo(tArbol *pa)
{
    if(!*pa)
        return 0;

    while((*pa)->der)
        pa = &(*pa)->der;

    return (tNodo **)pa;
}

tNodo **menorNodo(tArbol *pa)
{
    if(!*pa)
        return 0;

    while((*pa)->izq)
        pa = &(*pa)->izq;

    return (tNodo **)pa;
}

<<<<<<< Updated upstream
tNodo **buscarNodo(const tArbol *p, const void *dato, Cmp cmp)
=======
t_nodo **buscarNodo(const t_arbol *p, const void *dato, Cmp cmp)
>>>>>>> Stashed changes
{
    int res;
    if(!*p)
        return NULL;
    res = cmp(dato, (*p)->info);
    if(res>0)
        return buscarNodo(&(*p)->der, dato, cmp);
    if(res<0)
        return buscarNodo(&(*p)->izq, dato, cmp);

    return (tNodo **)p;
}

int crearArbolIndice(const char* ruta, tArbol* a, unsigned tamDatoReg, unsigned tamClave, Cmp cmp, Accion accion)
{
    char *datoReg = malloc(tamDatoReg);
    if(!datoReg)
        return 0;

    char *idx = malloc(tamClave+sizeof(unsigned));
    if(!idx)
        return 0;

    if(*a)
        return 0;

    unsigned nroReg = 0;
    FILE* pf = fopen(ruta, "rb");
    if(!pf)
        return 0;


    while(fread(datoReg, tamDatoReg, 1, pf))
    {
        accion(idx, datoReg);///copia en idx la clave que esta dentro de dato_reg
        memcpy(idx+tamClave, &nroReg, sizeof(unsigned));
        insertarEnArbol(a, idx, tamClave+sizeof(unsigned),cmp);
        nroReg++;
    }

    fclose(pf);
    free(datoReg);

    return 1;
}
