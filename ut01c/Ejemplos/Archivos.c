#include <stdio.h>
#define BUFFER_SIZE 100

int main() {
    // Abrir el archivo en modo escritura de texto
    FILE* archivo = fopen("datos.txt", "w");

    //Comprobar si se pudo abrir el archivo
    if (archivo == NULL) {
        perror("No se pudo abrir el archivo");
        return 1;
    }

    // Escribir líneas de texto en el archivo
    fprintf(archivo, "Hola, mundo!\n");
    fprintf(archivo, "Este es un archivo de texto.\n");

    // Cerrar el archivo
    fclose(archivo);

    // Abrir el archivo en modo lectura de texto
    archivo = fopen("datos1.txt", "r");

    //Comprobar si se pudo abrir el archivo
    if (archivo == NULL){
        perror("No se pudo abrir el archivo");
        return 1;
    }

    // Leer y mostrar las líneas de texto desde el archivo
    printf("Leyendo el archivo de texto:\n");
    char linea[BUFFER_SIZE];

    while (fgets(linea, sizeof(linea), archivo) != NULL) //Fget solo puede leer una linea de archivo a si que se usa while para leer archivo hasta que no encuentra nada.
    {
        printf("%s",linea);
    }
    
    //Solucion malo pero si tiene sola una linea el archivo si la puede hacerlo
    // if(archivo != NULL)
    // {
    //     fgets(linea, sizeof(linea), archivo);
    //     printf("%s",linea);
    // }else{
    //     ferror("No se puede abir archivo o no encuentra archivo");
    // }

    // Cerrar el archivo
    fclose(archivo);

    return 0;
}