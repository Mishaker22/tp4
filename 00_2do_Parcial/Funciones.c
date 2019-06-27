#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"

int pedirEnteroPositivo(char mensaje[], int* pInt){
    int estado= -1;
    if(pInt != NULL){
        printf("%s: ",mensaje);
        scanf("%d", pInt);
        while(*pInt <= 0 ){
            printf("\nError. %s: ", mensaje);
            scanf("%d", pInt);
        }
        estado= 0;
    }
    return estado;
}


int pedirEnteroRango(char mensaje[], int* pInt, int minimo, int maximo){
    int estado= -1;
    if (pInt != NULL){
        printf("%s: ", mensaje);
        scanf("%d", pInt);
        while(*pInt < minimo || *pInt > maximo){
            printf("\nError. %s: ", mensaje);
            scanf("%d", pInt);
        }
        estado= 0;
    }
    return estado;
}


int validarTamCadena(char mensaje[], char* pCadena, int tamanio){

    int estado= -1;
    unsigned int tam= (unsigned int)tamanio;
    if(pCadena != NULL){
        while( strlen(pCadena) > tam){
            printf("Error. %s: ", mensaje);
            fflush(stdin);
            scanf("%[^\n]", pCadena);
        }
        estado= 0;
    }
    return estado;
}


int pedirCadena(char mensaje[], char* pCadena, int tam){
    int estado= -1;
    char buffer[1000];
    if(pCadena != NULL){
        printf("%s: ", mensaje);
        fflush(stdin);
        scanf("%[^\n]", buffer);
        validarTamCadena(mensaje, buffer, tam);
        strcpy(pCadena, buffer);
        estado= 0;
    }
    return estado;
}

