#include <stdio.h>
#define n 5 //Maximo del arreglo

void menu() {
    printf("\n===========Menu===========\n"
           "1.- Encolar.\n"
           "2.- Desencolar.\n"
           "3.- Mostrar.\n"
           "4.- Salir.\n");
} //Menu principal
void encolar(int contador, int array[]) {
    do {
        printf("\nIngrese un numero a encolar:");
        scanf(" %d", &array[contador]);
        if (array[contador] < 0) { //Filtra valores negativos
            printf("Elige un numero entero positivo.");
        }
    }while (array[contador] < 0);
}
void desencolar(int array[]) {
    int opcion;

    do {
        printf("\nIngrese una opcion 1) FIFO, 2) LIFO:");
        scanf(" %d", &opcion);
        switch (opcion) {
            case 1:
                for (int i = 0; i < n - 1; i++) {
                    array[i] = array[i + 1];
                }
                array[n - 1] = 0;
                break;
            case 2:
                for (int i = 4; i >= 0; i--) {
                    if (array[i] != 0) { //Se iguala el ultimo elemento a 0 (vacio)
                        printf("Elemento %d extraído usando LIFO.\n", array[i]);
                        array[i] = 0;
                        break;
                    }
                }
                break;
            default:
                printf("\nIngrese una opcion valida.\n");
                break;
        }
    }while (opcion != 1 && opcion !=  2);
}

int main() {
    int contador = 0, opcion, array[n] = {0};

    do {
        menu();
        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                if (contador < n) {
                    encolar(contador, array);
                } else printf("\nArreglo lleno.");
                contador++;
                break;
            case 2:
                desencolar(array);
                contador--;
                break;
            case 3:
                for (int i = 0; i < n; i++) printf("%d ", array[i]); //Muestra arreglo
                break;
            case 4:
                printf("\nHasta luego :).");
                break;
            default:
                printf("\nOpcion no valida.");
        }
    }while (opcion != 4);
    return 0;
}