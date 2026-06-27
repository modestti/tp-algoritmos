#include "Utilitarias.h"

generarArchivoBinDesdeArchivoTxt(const char *pathTxt)
{
    char[TAM_LINEA] linea;
    FILE* pTxt = fopen(pathTxt, "rt");

    if(pTxt == NULL)
        return ERROR_ARCH;

    FILE* pBin = fopen(pathTxt, "wb");

    if(pBin == NULL)
        return ERROR_ARCH;

    fget(linea, )
}
