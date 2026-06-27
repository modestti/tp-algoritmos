#include "Utilitarias.h"

int generarArchivoBinDesdeArchivoTxt(char *pathTxt)
{
    char linea[TAM_LINEA];
    FILE* pTxt = fopen(pathTxt, "rt");

    if(pTxt == NULL)
        return ERROR_ARCH;

    FILE* pBin = fopen(pathTxt, "wb");

    if(pBin == NULL)
        return ERROR_ARCH;

    //fget(linea, )
}
