#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 10 //Constante cantidad de elementos

int main() {

    int array[n], temp;
    srand(time(NULL)); //semilla aleatorio

    for (int i = 0; i < n; i++){ //Relleno de arreglo (1-100)
        array[i] = (rand() % 100)+1;
        printf("%d ", array[i]);
    }
    printf("<- Sin ordenar | Ordenado -> ");

    for (int i = 0; i < n - 1; i++) { //Algoritmo de ordenamiento
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) printf("%d ", array[i]); //Se imprime ordenado
    return 0;
}