#include "socio.h"


//VALIDACIONES
int cantDias(int mes, int anio){
    static int meses[12] = {31,28,31,30,31,31,30,31,30,31,30,31};

    if(mes == 2 && anioBisiesto(anio))
        return 29;

    return meses[mes-1];
}

int anioBisiesto(int anio){
    return ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0)?TRUE:FALSE;
}

int validarFecha(tFecha fecha){
    if(fecha.anio >= 1900 && fecha.anio <= 5000){
        if(fecha.mes >= 1 && fecha.mes <=12 && fecha.dia <= cantDias(fecha.mes, fecha.anio) && fecha.dia>=1){
            return TRUE;
        }
    }
    return FALSE;
}

int fechaBaja (const tFecha f_baja){
    return validarFecha(f_baja) ? VALIDADO : ERROR_FECHABAJA;
}
