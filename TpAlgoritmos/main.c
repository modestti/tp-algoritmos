#include "Utilitarias.h"
#include "Arbol/arbol.h"
#include "Indice/indice.h"
#include "Socio/socio.h"
int main()
{
    char path[TAM_PATH];
    printf("Ingrese la ruta de acceso del archivo socios:");
    fflush(stdin);
    gets(path);

    generarArchivoBinDesdeArchivoTxt(path);



    return 0;
}
