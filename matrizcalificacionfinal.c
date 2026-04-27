#include <stdio.h>
#define MAX_NOMBRE 50

void menu() {
    printf("\n===========Menu===========\n"
        "1.- Insertar datos.\n"
        "2.- Ver matriz.\n"
        "3.- Promedio Estudiantes.\n"
        "4.- Promedio materias.\n"
        "5.- Nota mas alta.\n"
        "6.- Salir.\n");
}//Menu
void llenado(char alumnos[][MAX_NOMBRE], float cals[][4]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            do {
                printf("\nIngresa el valor del alumno %s en la materia %d (0-100): ", alumnos[i], j + 1);
                scanf(" %f", &cals[i][j]); //Relleno de matriz
            } while (cals[i][j] < 0 || cals[i][j] > 100);
        }
    }
}
void mostrar(char alumnos[][MAX_NOMBRE], float cals[][4]) {
    for (int i = 0; i < 3; i++) {
        printf("\nAlumno: %s -> Calificaciones: ", alumnos[i]);
        for (int j = 0; j < 4; j++) {
            printf(" [%.2f]", cals[i][j]); //Doble ciclo para mostrar
        }
    }
}

int main() {
    int opcion = 0; //Declaracion de variables
    float cals[3][4] = {0};
    char alumnos[3][MAX_NOMBRE] = {"ISRAEL", "DAVID", "TORIBIO"};

    do {
        menu();
        printf("\nElige una opcion (1-6): ");
        scanf(" %d", &opcion);
        switch (opcion) {
            case 1:
                llenado(alumnos, cals);
                break;
            case 2:
                mostrar(alumnos, cals);
                break;
            case 3:
                for (int i = 0; i < 3; i++) {
                    float suma_a = 0;
                    for (int j = 0; j < 4; j++) {
                        suma_a += cals[i][j];
                    }
                    printf("\nPromedio de %s: %.2f", alumnos[i], suma_a / 4); //Promedio suma cal / materias
                }
                break;
            case 4:
                for (int j = 0; j < 4; j++){
                    float suma_c = 0;
                for (int i = 0; i < 3; i++){
                    suma_c += cals[i][j];
                }
                printf("\nPromedio de la materia %d: %.2f", j + 1, suma_c / 3); //Promedio suma cal / alumnos
            }
                break;
            case 5: {
                float cal_alta = 0;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 4; j++) {
                        if (cal_alta < cals[i][j]) cal_alta = cals[i][j]; //Igualacion cuando es mayor
                    }
                }
                if (cal_alta == 0) {
                    printf("\nMatriz vacia.");
                } else{
                    printf("\nLa nota mas alta es: %.2f", cal_alta);
                }
                break;
            }
            case 6:
                printf("Hasta luego :).");
                break;
            default:
                printf("\nOpcion no valida, intenta de nuevo.\n");
                break;
        }
    } while (opcion != 6);

    return 0;
}