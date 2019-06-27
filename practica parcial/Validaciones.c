#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Validaciones.h"




int funcionSoloLetras(char letra[])
{
    int i=0;
    while(letra[i] != '\0')
    {
        if((letra[i] != ' ') && (letra[i] < 'a' || letra[i] > 'z') && (letra[i] < 'A' || letra[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}
void FuncionGetString (char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin) ;
    gets(input) ;
}
int funcionGetStringLetras(char mensaje[],char input[])
{
    int retorno =0;
    char aux[256];
    FuncionGetString(mensaje,aux);
    if(funcionSoloLetras(aux))
    {
        strcpy(input,aux);
        retorno= 1;
    }
    return retorno ;
}
int funcionEsNum(char letra[])
{
     int i=0;
    while(letra[i] != '\0')
    {
        if(letra[i] < '0' || letra[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int funcionGetStringNumeros(char mensaje[],char input[])
{
   char aux[256];
   FuncionGetString(mensaje,aux);
   if(funcionEsNum(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
void funcionContinuarSiONo(char mensaje[],char input[])
{
    do
    {
        if(!funcionGetStringLetras(mensaje,input))
        {
            printf("Error Debe ingresar la letra S o N");
            system("pause");
            system("cls");
        }

    }
    while(!(input[0] == 's' || input[0] == 'n' || input[0] == 'S' || input[0] == 'N'));

}


void validarTamCadena(char mensaje[], char cadena[], int tam){
    while( strlen(cadena) > tam){
        printf("Error. %s: ", mensaje);
        fflush(stdin);
        scanf("%[^\n]", cadena);
    }
}

int pedirCadena(char mensaje[], char* pCadena, int tam)
{
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


int pedirEnteroPositivo(char mensaje[], int* pInt)
{
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

int enteroRango(char mensaje[], int* pInt, int minimo, int maximo){
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
int menu()
{
    int opcion;
    enteroRango("\n1. CARGAR EMPLEADOS DE data.csv (MODO TEXTO)"
                         "\n2. CARGAR EMPLEADOS DE data.bin (MODO BINARIO)"
                         "\n3. ALTA DE EMPLEADO"
                         "\n4. MODIFICAR EMPLEADO"
                         "\n5. BAJA DE EMPLEADO"
                         "\n6. LISTAR EMPLEADOS"
                         "\n7. ORDENAR EMPLEADOS"
                         "\n8. GUARDAR EMPLEADOS EN data.csv (MODO TEXTO)"
                         "\n9. GUARDAR EMPLEADOS EN data.bin (MODO BINARIO)"
                         "\n10. SALIR\n\nElija una opcion", &opcion, 1, 10);

    return opcion;
}

