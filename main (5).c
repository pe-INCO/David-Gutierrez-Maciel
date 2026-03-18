#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int arreglo[10];
int menu=0;
int z;
int num;
int t=1;
int d=0;
int main(){
 arreglo[6]=0;
 arreglo[5]=0;
arreglo[12]=0;
arreglo[11]=0;//// para que todos los arreglos sea 0 al inicio
arreglo[7]=0;
arreglo[8]=0;
arreglo[9]=0;
arreglo[10]=0;
printf("1 Inicializar\n");
printf("2 Mostrar\n");
printf("3 Agregar\n");
printf("4 Insertar\n");
printf("5 Eliminar \n");
printf("6 Salir\n");
//los 0 son espacios vacios 
while(menu!=6){//para repetir el codigo
    scanf("%d",&menu);
switch(menu) {

	case  1:
    srand((unsigned int)time(NULL));
    printf("ya estan asignados:\n");
    for (int i = 0; i < 6; i++) {
        int num = rand() % 100; // Rango 0-99 random
         arreglo[i]=num;
         d=i;
    }
		break;
	case 2:
while(t<12){
     printf("%d\n",arreglo[t]);
     t=t+1;
}
t=1;
 printf("arreglo mostrado\n");
		break;
	case 3:
	d=d+1;
	    printf("agrega el numero que quieras\n");
	    scanf("%d",&arreglo[d]);
	    printf("agregado\n")

		break;
	case 4:
	    printf("agrega el numero que quieras en la posicion que quieras, primero dame la posicion\n");
	    scanf("%d",&z);
	    scanf("%d",&arreglo[z]);
	    printf("agregado\n")

		break;
	case 5:
	    printf("elimina un elemento en la posicion que escribas\n");
	    scanf("%d",&z);
	    scanf("%d",&arreglo[z]);
	    printf("agregado\n")
	    
	    

		break;
    default:
            printf("sin cambios\n");
            break;
    }
}
    


////mo tengo idea de porque se muestra un 2  en una posicion que no deberia
    

    return 0;
}