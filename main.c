#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Crear una función llamada aplicarDescuento que reciba como parámetro el precio de un producto y
devuelva el valor del producto con un descuento del 5%. Realizar la llamada desde el main.*/

/*Crear una función que se llame contarCaracteres que reciba una cadena de caracteres como primer
parámetro y un carácter como segundo y devuelva la cantidad de veces que ese carácter aparece en la cadena*/

/*Dada la estructura Notebook(id, procesador, marca, precio) generar una función que permita ordenar un
array de dicha estructura por marca. Ante igualdad de marca deberá ordenarse por precio. Hardcodear datos
y mostrarlos desde el main.*/


float aplicarDescuento(float precio);

int contarCaracteres(char cadena[], char caracter);

typedef struct{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
}eNotebook;

void ordenar(eNotebook notebooks[], int tam);



int main()
{
    float descuento;
    descuento = aplicarDescuento(100);
    printf("%.2f\n", descuento);

    int cantidad;
    cantidad = contarCaracteres("AAOOEEE", 'E');
    printf("%d\n", cantidad);

    eNotebook notebooks[3];
    notebooks[0].id = 1;
    strcpy(notebooks[0].procesador, "INTEL CORE I3");
    strcpy(notebooks[0].marca, "HP") ;
    notebooks[0].precio =  9000;

    notebooks[1].id = 2;
    strcpy(notebooks[1].procesador, "INTEL CORE I5");
    strcpy(notebooks[1].marca, "ASUS") ;
    notebooks[1].precio =  15000;

    notebooks[2].id = 3;
    strcpy(notebooks[2].procesador, "AMD Ryzen 3");
    strcpy(notebooks[2].marca, "SAMSUNG") ;
    notebooks[2].precio =  10000;

    ordenar(notebooks, 3);

    printf("%s ", notebooks[0].marca);
     printf("%s ", notebooks[1].marca);
      printf("%s", notebooks[2].marca);
    return 0;
}

float aplicarDescuento(float precio)
{
    return precio - 5*precio/100;
}

int contarCaracteres(char cadena[], char caracter)
{
    int tam = strlen(cadena);
    int contador =0;
    for(int i=0; i<tam; i++)
    {
        if(cadena[i] == caracter)
        {
            contador++;
        }
    }
    return contador;
}

void ordenar(eNotebook notebooks[], int tam)
{
    eNotebook aux;
    for(int i=0; i<tam-1; i++)
    {
        for(int x=i+1; x<tam; x++)
        {
            if(strcmp(notebooks[i].marca, notebooks[x].marca)> 0)
            {
                aux = notebooks[i];
                notebooks[i] = notebooks[x];
                notebooks[x] = aux;
            }
            if(strcmp(notebooks[i].marca, notebooks[x].marca)== 0 && notebooks[i].precio > notebooks[x].precio)
            {
                aux = notebooks[i];
                notebooks[i] = notebooks[x];
                notebooks[x] = aux;
            }
        }
    }
}
