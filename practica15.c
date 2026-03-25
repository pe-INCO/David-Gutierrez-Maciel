#include <stdio.h>
int box[9];//areglo
int d;//pocision
int dd=0;//marcador de si esta
int buscar;

int main()
{

box[0]=23;
box[1]=65;
box[2]=98;
box[3]=46;
box[4]=71;///asignar valores
box[5]=67;
box[6]=45;
box[7]=37;
box[8]=34;
box[9]=99;
	printf("que numero deseas buscar");
	scanf("%d",&buscar);///numero a buscar
	    for (int i = 0; i <= 9; i++) {///revisa todas la pocisiones
        if(box[i]==buscar){
        d=i;
        dd=10;//comprobar los numeros
        
        }
    }
    if(dd==10){
      printf("el numero si esta en la pocision : %d",d);///mesaje si si esta 
      
    }else{
        printf("el numero no esta"); ///mesaje si no esta 
      
    }

	return 0;
}