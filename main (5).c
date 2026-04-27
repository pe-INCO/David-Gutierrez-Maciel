#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu() {
    printf("\n----------------- MENU -----------------" //MENU
        "\n1.-Inicializar arreglo con valores aleatorios [5]\n"
        "2.-Mostrar arreglo actual\n"
        "3.-Agregar elemento al final\n"
        "4.-Insertar elemento en posicion especifica\n"
        "5.-Eliminar elemento por posicion\n"
        "6.-Salir\n\n"
        "Elige una opcion:");
}

int main() {
    int arr[10] = {0}, tam = 0, opcion, posicion, valor;
    srand(time(NULL)); //Semilla numero aleatorio

    do {
        menu();
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                tam = 5;
                for (int i = 0; i < tam; i++) {
                    arr[i] = (rand() % 100)+1; //Num aleatorio (1-100) para los primeros 5
                }
                printf("El arreglo inicializo sus primeros valores aleatoriamente\n");
                break;
            case 2:
                if (tam != 0) {
                    printf("Tu arreglo es:\n");
                    for (int i = 0; i < 10; i++) { //Se imprime cuando el valor no sea nulo
                        if (arr[i] != 0) {
                            printf("\n%d.- %d ", i + 1, arr[i]);
                        }
                    }
                } else printf("\nEl arreglo esta vacio\n");
                break;
            case 3:
                if (tam < 10) {
                    printf("\nIngrese el valor a agregar (1-100):");
                    scanf("%d", &valor);

                    if (valor <= 100 && valor > 0) {
                        arr[tam] = valor;
                        tam++;
                    } else printf("\nValor invalido\n");
                } else printf("\nArreglo lleno\n");
                break;
            case 4:
                printf("\nIngrese el valor a agregar (1-100) y separado con un espacio la posicion (1-10):");
                scanf("%d %d", &valor ,&posicion);

                if ((valor <= 100 && valor > 0) && (posicion <= 10 && posicion > 0)) {
                    arr[posicion - 1] = valor; //se inserta valor al arreglo
                    if(posicion > tam) tam = posicion;
                } else printf("\nValor o posicion invalida\n");
                break;
            case 5:
                printf("\nIngrese la posicion a eliminar:");
                scanf("%d", &posicion);

                if (posicion <= 10 && posicion > 0) {
                    arr[posicion - 1] = 0; //Lo vuelve 0 (fuera de rango)
                } else printf("\nPosicion invalida\n");
                break;
            case 6:
                printf("Hasta luego :)");
                break;
            default:
                printf("\nOpcion invalida\n");
                break;
        }
    }while (opcion != 6);
    return 0;
}