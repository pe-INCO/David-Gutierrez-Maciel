#include <stdio.h>

int main() {
    int ID = 0;
    int sirg = 0;
    char reinicio[100];
    FILE *archivo;

    // Usamos do-while para que el menú se ejecute al menos una vez
    do {
        printf("\n=== MENU ===\n");
        printf("1.- Crear (Añadir)\n");
        printf("2.- Leer\n");
        printf("3.- Sobreescribir todo\n");
        printf("4.- Salir\n");
        printf("Selecciona una opcion: ");
        
        scanf("%d", &sirg);
        
        // Limpiar el buffer (elimina el 'Enter' sobrante)
        while(getchar() != '\n'); 

        switch(sirg) {
            case 1:
                archivo = fopen("datos.txt", "a");
                if (archivo == NULL) {
                    printf("Error al abrir el archivo\n");
                } else {
                    ID++; // El ID aumenta en cada registro
                    fprintf(archivo, "ID: %d - Registro añadido correctamente\n", ID);
                    fclose(archivo);
                    printf("Dato guardado.\n");
                }
                break;
            
            case 2:
                char linea[100];
                archivo = fopen("datos.txt", "r");
                if (archivo == NULL) {
                    printf("Error: El archivo no existe todavia.\n");
                } else {
                    printf("\n--- Contenido del archivo ---\n");
                    while (fgets(linea, sizeof(linea), archivo) != NULL) {
                        printf("%s", linea);
                    }
                    fclose(archivo);
                }
                break;

            case 3:
                archivo = fopen("datos.txt", "w"); // "w" limpia el archivo
                if (archivo == NULL) break;
                
                printf("Introduce el nuevo contenido: ");
                fgets(reinicio, sizeof(reinicio), stdin);
                
                fprintf(archivo, "%s", reinicio);
                fclose(archivo);
                printf("Archivo sobreescrito.\n");
                break;

            case 4:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion no valida.\n");
                break;
        }
    } while(sirg != 4); // El bucle sigue mientras no elijas 4
    
    return 0;
}
