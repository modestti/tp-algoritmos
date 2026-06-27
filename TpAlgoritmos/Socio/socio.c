#include "socio.h"


//VALIDACIONES FECHA
int cantDias(int mes, int anio)
{
    static int meses[12] = {31,28,31,30,31,31,30,31,30,31,30,31};

    if(mes == 2 && anioBisiesto(anio))
        return 29;

    return meses[mes-1];
}

int anioBisiesto(int anio)
{
    return ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0)?TRUE:FALSE;
}

int validarFecha(tFecha fecha)
{
    if(fecha.anio >= 1900 && fecha.anio <= 5000)
    {
        if(fecha.mes >= 1 && fecha.mes <=12 && fecha.dia <= cantDias(fecha.mes, fecha.anio) && fecha.dia>=1)
        {
            return TRUE;
        }
    }
    return FALSE;
}

int fechaBaja (const tFecha f_baja)
{
    return validarFecha(f_baja) ? VALIDADO : ERROR_FECHABAJA;
}


int fechaAfiliacion (const tFecha afiliacion)
{
    return validarFecha(afiliacion) ? VALIDADO : ERROR_AFILIACION;
}

int fechaNacimiento(const tFecha nac)
{
    return validarFecha(nac) ? VALIDADO : ERROR_FECHANACIMIENTO;
}

int ultCuota (const tFecha ultc)
{
    return validarFecha(ultc) ? VALIDADO : ERROR_FECHAULTCUOTA;
}


//VALIDACIONES SOCIO
int sexo (char s)
{
    s = TOUPPER(s);
    return SEXO_VALIDO(s) ? VALIDADO : ERROR_SEXO;
}


int estado (char e)
{
    e = TOUPPER(e);
    return ESTADO_VALIDO(e) ? VALIDADO : ERROR_ESTADO;
}


void strtoupper(char *str)
{
    while(*str)
    {
        *str = TOUPPER(*str);
        str++;
    }
}

int categoria(char* cat)
{
    const char* opc[] = {"MENOR", "CADETE", "ADULTO","VITALICIO", "HONORARIO", "JUBILADO"};
    strtoupper(cat);
    for(int i=0; i<6; i++)
    {
        if(strcmp(cat, opc[i])==0)
            return VALIDADO;
    }
    return ERROR_CATEGORIA;
}


int dni(long id)
{
    return (id>10000 && id<100000000)? VALIDADO : ERROR_DNI;
}


int validarUnaPalabra(char *cadena, int tam)
{
    int i= 0;
    int encontradoLetra=0;
    int encontradoFin=0;
    while(i<tam&&encontradoFin==0)
    {
        if(cadena[i] == '\0')
        {
            encontradoFin = 1;
        }
        else
        {
            if(!ES_LETRA(cadena[i]))
                return FALSE;

            encontradoLetra = 1;
        }
        i++;
    }
    return (encontradoLetra == 1 && encontradoFin == 1) ? TRUE : FALSE;
}


void normalizarCadena(char *cadena)
{
    char *cursorLeer = cadena;
    char *cursorEscribir = cadena;

    int inicioPalabra = 1;

    while(*cursorLeer != '\0')
    {
        if (*cursorLeer == ' ')
        {
            if(!inicioPalabra)
            {


                *cursorEscribir = ' ';
                cursorEscribir++;
                inicioPalabra = 1;
            }

        }
        else
        {
            if (inicioPalabra)
            {

                *cursorEscribir = toupper((unsigned char)*cursorLeer);
                cursorEscribir++;
                inicioPalabra = 0;
            }
            else
            {

                *cursorEscribir = tolower((unsigned char)*cursorLeer);
                cursorEscribir++;
            }
        }
        cursorLeer++;

    }
    if(cursorEscribir > cadena && *(cursorEscribir-1) == ' ' )
    {
        cursorEscribir--;
    }

    *cursorEscribir = '\0';


}

