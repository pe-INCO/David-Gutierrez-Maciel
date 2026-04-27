#include <stdio.h>

int busqueda(int arr[], int num_buscado);

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10}; //Declaracion de variables
    int num_buscado;

    printf("Escribe el numero que deseas buscar en el arreglo:");
    scanf(" %d", &num_buscado);

    if (busqueda(arr, num_buscado) > 0) {
        return 0;
    }
    printf("El valor %d no se encontro en el arreglo.", num_buscado);//No encontrado
    return 0;
}

int busqueda(int arr[], int num_buscado) {
    for (int i = 0; i < 10; i++) { //Ciclo de busqueda
        if (arr[i] == num_buscado) {
            printf("\nSe encontro el valor %d en la posicion: %d", num_buscado, i+1); //Encontrado
            return 1;
        }
    }
    return 0;
}