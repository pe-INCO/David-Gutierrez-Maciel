#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char frase[100];
    int terra;
    int vocal(char arroba) {//funcion quen comproba si son vocales tanto mayusculas como minusculas
    return (arroba == 'a' || arroba == 'e' || arroba == 'i' || arroba == 'o' || arroba == 'u' || arroba == 'A' || arroba == 'E' || arroba == 'I' || arroba == 'O'|| arroba == 'U' );
    }

    printf("Escribe una frase de menos de 100 carracteres: ");
    fgets(frase, 100, stdin);//para el tamaño de la cadena
    frase[strcspn(frase, "\n")] = '\0'; 
    printf("Cadena en Mayusculas: ");
        for (int i = 0; frase[i] != '\0'; i++)
        putchar(toupper(frase[i]));//cambia a mayusculas
        
     printf("\nCadena en Minusculas: ");
    for (int i = 0; frase[i] != '\0'; i++){
        putchar(tolower(frase[i]));// cambia a minusculas
        terra=i;
    }


            printf("\nprimeros 3 digitos\n");//imprime los 3 primeros digitos
            for (int i = 0; i < 3; i++) {
            printf("%c", frase[i]);
                
            }
            
            printf("\nultimos 3 digitos\n");//imprime los 3 ultimos digitos de ulmino al antepenultimo
            for (int i = 0; i < 3; i++) {
            printf("%c", frase[terra]);
                terra=terra-1;
            }
        
        
    printf("\nLongitud: %d caracteres\n", strlen(frase));
        for (int i = 0; frase[i] != '\0'; i++) {// usa la funcion para recisar si son vocales y si lo son los remplasa por un arrroba
        if (vocal(frase[i])) {
            frase[i]='@';
        
        }
    }
printf("Modificado:  %s\n", frase);//muestra las cadena con los arrobs
    return 0;
}