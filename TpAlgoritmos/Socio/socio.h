#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define TAM_APYNOM 60
#define TAM_CATEG 10
typedef struct
{
    int d;
    int m;
    int a;
}t_fecha

typedef struct
{
    unsigned long dni;
    char apellidos[TAM_APYNOM];
    char nombres[TAM_APYNOM];
    t_fecha fechaNacimiento;
    char sexo;
    t_fecha fechaAfiliacion;
    char categoria[TAM_CATEG];
    t_fecha fechaUltCuoPaga;
    char estado;
    t_fecha fechaBaja;

}t_socio;



#endif // SOCIO_H_INCLUDED
