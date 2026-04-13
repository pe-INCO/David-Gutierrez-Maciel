#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 10

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void quicksort(int a[], int low, int high) {
    if (low < high) {
        int pivot = a[high]; // Elegimos el último elemento como pivote
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (a[j] < pivot) {
                i++;
                swap(&a[i], &a[j]);
            }
        }
        swap(&a[i + 1], &a[high]);
        int pi = i + 1;

        // Ordenar las dos mitades
        quicksort(a, low, pi - 1);
        quicksort(a, pi + 1, high);
    }
}
void insertionSort(int arr[]) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int array[n], opcion;
    srand(time(NULL));

    printf("Arreglo original: ");
    for (int i = 0; i < n; i++){
        array[i] = (rand() % 100) + 1;
        printf("%d ", array[i]);
    }

    do {
        printf("\n\nElige el algoritmo para ordenar: 1) Quicksort. 2) Insertion sort.\n");
        scanf("%d", &opcion);

        if (opcion == 1) {
            quicksort(array, 0, n - 1);
        } else if (opcion == 2) {
            insertionSort(array);
        }
        if (opcion != 2 && opcion != 1) {
            printf("\nOpcion invalida.");
        }
    }while (opcion != 2 && opcion != 1);

    printf("Arreglo ordenado: ");
    for (int i = 0; i < n; i++) printf("%d ", array[i]);

    return 0;
}