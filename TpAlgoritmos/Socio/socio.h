#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define TAM_APYNOM 60
#define TAM_CATEG 10

#define TRUE 1
#define FALSE 0
#define ERROR_FECHABAJA 0
#define VALIDADO 1

typedef struct
{
    int dia;
    int mes;
    int anio;
}tFecha;

typedef struct
{
    unsigned long dni;
    char apellidos[TAM_APYNOM];
    char nombres[TAM_APYNOM];
    tFecha fechaNacimiento;
    char sexo;
    tFecha fechaAfiliacion;
    char categoria[TAM_CATEG];
    tFecha fechaUltCuoPaga;
    char estado;
    tFecha fechaBaja;

}tSocio;


//VALIDACIONES
int cantDias(int mes, int anio);
int anioBisiesto(int anio);
int validarFecha(tFecha fecha);
int fechaBaja (const tFecha f_baja);



#endif // SOCIO_H_INCLUDED
