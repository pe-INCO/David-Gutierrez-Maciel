#include <stdio.h>

int main() {
    int sirg=0;
    char reinicio[100];
    FILE *archivo;
    printf(" menu\n");
    printf("1 crear\n");
    printf("2 leer\n");
    printf("3 sobreescibir\n");
    scanf("%d",&sirg);
    // Abrir archivo en modo escritura ("w" crea o sobrescribe)
    switch(sirg){
    case 1:
    archivo = fopen("datos.txt", "a");
    
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }
    
    // Escribir en el archivo
    fprintf(archivo, "Hola, este es un ejemplo de manejo de archivos\n");
    fprintf(archivo, "Número: %d\n", 42);
    fprintf(archivo, "Línea final del archivo.\n");
    
    // Cerrar el archivo
    fclose(archivo);
    break;
    
    case 2:
    char linea[100];
    
    // Abrir archivo en modo lectura ("r")
    archivo = fopen("datos.txt", "r");
    
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo\n");
        return 1;
    }
    
    // Leer y mostrar línea por línea
    printf("Contenido del archivo:\n");
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        printf("%s", linea);
    }
    
    // Cerrar el archivo
    fclose(archivo);
    break;
    case 3:
            
            archivo = fopen("datos.txt", "w");
            if (archivo == NULL) return 1;
            
            printf("Introduce el nuevo contenido del archivo: ");
            fgets(reinicio, sizeof(reinicio), stdin); // L
            
            fprintf(archivo, "%s", reinicio);
            fclose(archivo);
            printf("archivo sobreescrito \n");
            break;

        default:
            printf("opcion no valida.\n");
            break;
    }
    
    return 0;
}
