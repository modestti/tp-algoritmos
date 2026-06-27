#include "Utilitarias.h"


int generarArchivoBinDesdeArchivoTxt(const char *pathTxt)
{
    char linea[TAM_LINEA];
    tSocio socio;

    FILE* pTxt = fopen(pathTxt, "rt");

    if(pTxt == NULL)
    {
        printf("Error apertura de archivo de texto");
        return ERROR_ARCH;
    }

    FILE* pBin = fopen(pathBin, "wb");

    if(pBin == NULL)
    {
        printf("Error creacion de archivo de binario");
        fclose(pTxt);
        return ERROR_ARCH;

    }
    fgets(linea,TAM_LINEA,pTxt);
    while(fgets(linea,TAM_LINEA,pTxt))
    {
        sscanf(linea, "%lu,%59[^,],%59[^,],%d/%d/%d,%c,%d/%d/%d,%9[^,],%d/%d/%d,%c,%d/%d/%d",&socio.dni,socio.apellidos,socio.nombres,&socio.fechaNacimiento.dia,&socio.fechaNacimiento.mes,
               &socio.fechaNacimiento.anio,&socio.sexo,&socio.fechaAfiliacion.dia,&socio.fechaAfiliacion.mes,&socio.fechaAfiliacion.anio,socio.categoria,&socio.fechaUltCuoPaga.dia,
               &socio.fechaUltCuoPaga.mes, &socio.fechaUltCuoPaga.anio,&socio.estado,&socio.fechaBaja.dia,&socio.fechaBaja.mes,&socio.fechaBaja.anio);

        fwrite(&socio,sizeof(tSocio),1,pBin);


    }
    fclose(pTxt);
    fclose(pBin);


    return TODO_BIEN;
}
