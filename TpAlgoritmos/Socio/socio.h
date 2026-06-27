#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define TAM_APYNOM 60
#define TAM_CATEG 10

#define TRUE 1
#define FALSE 0
#define ERROR_FECHABAJA 0
#define ERROR_SEXO 0
#define ERROR_ESTADO 0
#define ERROR_AFILIACION 0
#define ERROR_CATEGORIA 0
#define ERROR_FECHANACIMIENTO 0
#define ERROR_DNI 0
#define ERROR_FECHAULTCUOTA 0
#define VALIDADO 1

#define TOUPPER(X) (((X) >= 'a' && (X) <= 'z') ? (X) - 32 :(X))
#define ES_LETRA(c) (((c) >= 'A' && (c) <= 'Z') || ((c) >= 'a' && (c) <= 'z'))
#define SEXO_VALIDO(c) ((c)=='M'||(c)=='F'||(c)=='O')
#define ESTADO_VALIDO(c) ((c)=='A'||(c)=='I')

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



//VALIDACIONES FECHA
int cantDias(int mes, int anio);
int anioBisiesto(int anio);
int validarFecha(tFecha fecha);
int fechaBaja (const tFecha f_baja);
int fechaAfiliacion (const tFecha afiliacion);
int fechaNacimiento(const tFecha nac);
int ultCuota (const tFecha ultc);
int compararFechas(const void *f1, const void *f2);



//VALIDACIONES SOCIO
int sexo (char s);
int estado (char e);
void strtoupper(char *str);
int categoria(char* cat);
int dni(long id);
int validarUnaPalabra(char *cadena, int tam);
void normalizarCadena(char *cadena);
#endif // SOCIO_H_INCLUDED
