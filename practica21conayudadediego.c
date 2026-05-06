#include <stdio.h>
#include <ctype.h>
#include <string.h>

void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void menu() {
    printf("1.- Leer el archivo completo.\n"
           "2.- Agregar registro.\n"
           "3.- Actualizar registro.\n"
           "4.- Eliminar registro.\n"
           "5.- Salir\n");
}
void leer_completo() {
    FILE *archivo;
    char linea[100];

    archivo = fopen("datos.txt", "r"); // Abrir archivo en modo lectura ("r")

        printf("Contenido del archivo:\n"); // Leer y mostrar línea por línea
        while (fgets(linea, sizeof(linea), archivo) != NULL) {
            printf("%s", linea);
        }
    
    fclose(archivo);
}
void agregar_registro(int contador) {
    FILE *archivo;
    float arreglo_int[3] = {0, 0, 0};
    char arreglo_char[2][50];

    arreglo_int[2] = (float)contador;

    printf("Ingresa tu nombre:");
    fgets(arreglo_char[0], 50, stdin);
    arreglo_char[0][strcspn(arreglo_char[0], "\n")] = 0;

    printf("Ingresa tu sexo:");
    fgets(arreglo_char[1], 50, stdin);
    arreglo_char[1][strcspn(arreglo_char[1], "\n")] = 0;

    printf("Ingresa tu edad:");
    scanf("%f", &arreglo_int[0]);
    limpiar_buffer();

    printf("Ingresa tu peso (kg):");
    scanf("%f", &arreglo_int[1]);
    limpiar_buffer();

    archivo = fopen("datos.txt", "a");

    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
    } else {
        fprintf(archivo, "%.0f, %s, %s, %.0f, %.2f\n",
                arreglo_int[2], arreglo_char[0], arreglo_char[1],
                arreglo_int[0], arreglo_int[1]);
        fclose(archivo);
    }
}
void actualizar_registro() {
    FILE *archivo, *temporal;
    int id_buscado, id_temporal;
    char linea[100];
    int encontrado = 0; //Para saber si el ID existía

    char nuevo_nombre[50], nuevo_sexo[50]; //Variables de los nuevos datos
    float nueva_edad, nuevo_peso;

    printf("Ingresa el ID que deseas buscar: ");
    scanf("%d", &id_buscado);
    limpiar_buffer();

    archivo = fopen("datos.txt", "r");
    temporal = fopen("temporal.txt", "w");

    if (archivo == NULL || temporal == NULL) {
        printf("Error: No se pudo abrir el archivo\n");
        return;
    }

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        id_temporal = linea[0] - '0'; //Convertir caracter a numero

        if (id_buscado == id_temporal) {
            encontrado = 1;
            printf("Registro encontrado.\n\n");

            printf("Nuevo nombre: ");
            fgets(nuevo_nombre, 50, stdin);
            nuevo_nombre[strcspn(nuevo_nombre, "\n")] = 0;

            printf("Nuevo sexo: ");
            fgets(nuevo_sexo, 50, stdin);
            nuevo_sexo[strcspn(nuevo_sexo, "\n")] = 0;

            printf("Nueva edad: ");
            scanf("%f", &nueva_edad);
            printf("Nuevo peso (kg): ");
            scanf("%f", &nuevo_peso);
            limpiar_buffer();

            fprintf(temporal, "%d, %s, %s, %.0f, %.2f\n", // Escribimos la línea modificada en el temporal
                    id_temporal, nuevo_nombre, nuevo_sexo, nueva_edad, nuevo_peso);
        } else {
            fputs(linea, temporal); // Si no es el ID, copiamos la línea original tal cual
        }
    }

    fclose(archivo);
    fclose(temporal);

    if (encontrado) {
        remove("datos.txt"); // Borra el original
        rename("temporal.txt", "datos.txt"); // Renombra el temporal
        printf("Registro actualizado exitosamente.\n");
    } else {
        remove("temporal.txt"); // Borra el temporal si no se uso
        printf("No se encontro un registro con el ID %d\n", id_buscado);
    }
}
void borrar_registro() {
    FILE *archivo, *temporal;
    int id_buscado, id_temporal;
    char linea[100];
    int encontrado = 0; //Para saber si el ID existía

    printf("Ingresa el ID que deseas buscar: ");
    scanf("%d", &id_buscado);
    limpiar_buffer();

    archivo = fopen("datos.txt", "r");
    temporal = fopen("temporal.txt", "w");

    if (archivo == NULL || temporal == NULL) {
        printf("Error: No se pudo abrir el archivo\n");
        return;
    }

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        id_temporal = linea[0] - '0'; //Convertir caracter a numero

        if (id_buscado == id_temporal) {
            encontrado = 1;
        } else {
            fputs(linea, temporal); // Si no es el ID, copiamos la línea original tal cual
        }
    }

    fclose(archivo);
    fclose(temporal);

    if (encontrado) {
        remove("datos.txt"); // Borra el original
        rename("temporal.txt", "datos.txt"); // Renombra el temporal
        printf("Registro eliminado exitosamente.\n");
    } else {
        remove("temporal.txt"); // Borra el temporal si no se uso
        printf("No se encontro un registro con el ID %d\n", id_buscado);
    }
}
int ultimo_id() {
    FILE *archivo;
    int id_buscado = 0, id_temporal;
    char linea[100];

    archivo = fopen("datos.txt", "r");

    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo\n");
        return 0;
    }

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        if (isdigit(linea[0])) { //Confirma que el primer caracter es un numero
            id_temporal = linea[0] - '0';
            if (id_buscado < id_temporal) {
                id_buscado = id_temporal;
            }
        }
    }
    fclose(archivo);

    if (id_buscado > 0) {
        return id_buscado; //Retorna el ID mayor
    }
    printf("No se encontro un registro con el ID %d\n", id_buscado);

    return 0;
}

int main() {
    int opcion = 0;
    int contador = ultimo_id();

    do {
        menu();
        printf("\nSelecciona una opcion:");
        scanf("%d", &opcion);
        getchar();
        switch (opcion) {
            case 1:
                leer_completo();
                break;
            case 2:
                if (contador < 9) {
                    contador ++;
                    agregar_registro(contador);
                }else printf("Registros llenos.");
                break;
            case 3:
                actualizar_registro();
                break;
            case 4:
                borrar_registro();
                break;
            case 5:
                printf("seccion terminada");
                break;
            default:
                printf("\nOpcion no valida.\n");
        }
    } while (opcion != 5);
    return 0;
}