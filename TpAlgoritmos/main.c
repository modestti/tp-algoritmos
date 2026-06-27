#include "Utilitarias.h"
#include "Arbol/arbol.h"
#include "Indice/indice.h"
int main()
{
    char path[TAM] ;
    printf("Ingrese el path(ruta de acceso) del archivo");
    scanf("%s", path);
    generarArchivoBinDesdeArchivoTxt(path);
    //generarIndice();

    printf("Hello world!\n");
    return 0;
}
