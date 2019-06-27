#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Funciones.h"

#define ID_INICIO 100
#define PATH_TXT "datos.csv"
#define PATH_RESULTADOS_TXT "resultados.csv"




int main(){

    LinkedList* listaEmpleados= ll_newLinkedList();
    LinkedList* listaEmpleadosFiltrados = NULL;

    int ultimoId= ID_INICIO;
    int opcion;
    int flag= -1;

    do{
        if (ll_isEmpty(listaEmpleados) == 1){
            printf("\n\n-- No hay empleados en la lista, las opciones 2 a 5 estan deshabilitadas.--\n");
        }else if (ll_isEmpty(listaEmpleados) == -1){
            printf("\n\n-- No se pueden cargar empleados a la lista, las opciones 2 a 5 estan deshabilitadas.--\n");
        }
        pedirEnteroRango("\n1. CARGAR EMPLEADOS DE data.csv (MODO TEXTO)"
                         "\n2. LISTAR EMPLEADOS"
                         "\n3. CALCULAR SUELDOS"
                         "\n4. LISTAR CON SUELDOS"
                         "\n5. GUARDAR LISTADO FILTRADO EN resultados.csv (MODO TEXTO)"
                         "\n6. SALIR\n\nElija una opcion", &opcion, 1, 6);
        switch(opcion){
            case 1:
                if(controller_loadFromText(PATH_TXT, listaEmpleados) == -1){

                    printf("\n\nERROR. No se pudo realizar la carga desde datos.csv\n");
                }else{
                    controller_cargarUltimoId(listaEmpleados, &ultimoId);
                    printf("\n\n--Empleados cargados desde datos.csv--\n\n");
                }
            break;

            case 2:
                if(!ll_isEmpty(listaEmpleados)){
                    controller_sortEmployee(listaEmpleados);
                    controller_ListEmployee(listaEmpleados);
                }
                break;

            case 3:
                if(!ll_isEmpty(listaEmpleados)){
                    controller_calcularSueldo(listaEmpleados);
                    printf("\n\n--Sueldos calculados--\n\n");
                    flag= 0;
                }
                break;
            case 4:
                if(!ll_isEmpty(listaEmpleados) && flag == 0){
                    controller_ListEmployeeSueldo(listaEmpleados);
                }
                break;

            case 5:
                listaEmpleadosFiltrados= controller_filtrar(listaEmpleados);
                if(listaEmpleadosFiltrados != NULL){
                    printf("\n\n--Empleados filtrados--\n\n");
                    controller_ListEmployee(listaEmpleadosFiltrados);

                    if(controller_saveAsText(PATH_RESULTADOS_TXT, listaEmpleadosFiltrados)==0){
                        printf("\n\n--Datos guardados en %s (MODO TEXTO)--\n\n", PATH_RESULTADOS_TXT);
                    }else{
                        printf("\nError. No se pudieron guardar los datos en %s\n\n",PATH_RESULTADOS_TXT);
                    }
                }else{
                    printf("\nError. No hay empleados en la lista de empleados filtrados\n\n");
                }

                break;
            case 6:
                printf("\n\nSaliendo del sistema.\n");
                ll_clear(listaEmpleados);
                ll_clear(listaEmpleadosFiltrados);
                ll_deleteLinkedList(listaEmpleados);
                ll_deleteLinkedList(listaEmpleadosFiltrados);
        }
    }while(opcion != 6);

    return 0;
}


