#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Empleado.h"
#include "controller.h"
#include "parser.h"
#include "Validaciones.h"

#define OK 0
#define ERROR -1

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int estado= ERROR;

    FILE* unArchivo= fopen(path, "r");

    if((unArchivo == NULL) && (pArrayListEmployee == NULL))
    {
        printf("\nEl archivo a cargar no existe..");
    }else
    {
        ll_clear(pArrayListEmployee);
        estado= parser_EmployeeFromText(unArchivo, pArrayListEmployee);
        fclose(unArchivo);

    }

    return estado;
}
int controller_addEmployee(LinkedList* pArrayListEmployee, int* ultimoId){
    int id;
    char nombre[TAM_CADENA];
    char empleo[TAM_CADENA];
    int edad;
    int horasTrabajadas;

    int estado= ERROR;
    if(pArrayListEmployee != NULL && ultimoId != NULL){
        pedirCadena("Ingrese el nombre",nombre,TAM_CADENA);
        pedirCadena("Ingrese el empleo",empleo,TAM_CADENA);
        pedirEnteroPositivo("Ingrese la edad", &edad);
        pedirEnteroPositivo("Ingrese las horas trabajadas", &horasTrabajadas);

        id= *ultimoId;
        id++;
        Employee* this= employee_newParametros(id,nombre,empleo,edad,horasTrabajadas);
        ll_add(pArrayListEmployee, this);
        *ultimoId= id;
        estado= OK;
    }
    return estado;
}
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int estado=ERROR;
    int id;
    char nombre[20];
    int horasTrabajadas;
    int sueldo;
    int indice=-1;
    int i;
    char seguir[1];
    Employee* this;

    if(pArrayListEmployee !=NULL)
    {
        if(pedirEnteroPositivo("\n Ingrese el id del empleado que desea modificar", &id))
        {
            printf("\nError el id solo debe contener numeros.");
        }
        for(i=0;i<ll_len(pArrayListEmployee);i++){
            this= (Employee*)ll_get(pArrayListEmployee, i);
            if( this->id == id ){
                indice= i;
                break;
            }
    }

    if (indice == -1)
    {
        printf("No hay ningun empleado con ese numero id..  \n\n");
        system("pause");
    }else{


        employee_mostrarUno(this);

        funcionContinuarSiONo("\n¿Desea cambiar el Nombre? s/n",seguir);

        if(seguir[0]=='n'|| seguir[0]=='N')
        {
            printf("\nNo ha modificado el nombre.");
        }else if(pedirCadena("\nIngrese el nuevo nombre: ",nombre, 20))
        {
            printf("\n Error. el nombre solo debe contener letras.");
        }else{

            employee_setNombre(this,nombre);
            printf("\nEl nombre ha sido modificado!");
        }
        //MODIFICAR HORAS TRABAJADAS

        employee_mostrarUno(this);

        funcionContinuarSiONo("\n¿Desea cambiar las horas trabajadas? s/n", seguir);

        if(seguir[0]=='n'|| seguir[0]=='N')
        {
            printf("\n No ha modificado las horas.");
        }else if(pedirEnteroPositivo("\n Ingrese la Nueva cantidad de horas de trabajo:",&horasTrabajadas))
        {
            printf("\nError solo debe contener numeros.");
        }else{

            employee_setHorasTrabajadas(this, horasTrabajadas);
            printf("\nLas Horas han sido modificadas!");
        }

        //MODIFICAR SUELDO

        employee_mostrarUno(this);
        funcionContinuarSiONo("\n¿Desea cambiar el sueldo? s/n", seguir);

        if(seguir[0]=='n'|| seguir[0]=='N')
        {
            printf("\n No ha modificado el sueldo.");
        }else if(pedirEnteroPositivo("\n Ingrese el nuevo salario:",&sueldo))
        {
            printf("\nError solo debe contener numeros.");
        }else{

            employee_setSueldo(this, sueldo);
            printf("\nEl sueldo ha sido modificado!");
            }
        estado=OK;
        }
    }
    return estado;
}
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int indice=-1;
    int estado=ERROR;
    int id;
    int i;
    char seguir[1];
    Employee* this;

    if(pArrayListEmployee !=NULL)
    {
         if(pedirEnteroPositivo("\n Ingrese el id del empleado que desea eliminar", &id))
        {
            printf("\nError el id solo debe contener numeros.");
        }
        for(i=0;i<ll_len(pArrayListEmployee);i++)
            {
            this= (Employee*)ll_get(pArrayListEmployee, i);
            if( this->id == id )
                {
                indice= i;
                break;
                }
            }
        if(indice==-1)
        {
            printf("No hay ningun empleado con ese numero id..  \n\n");
            system("pause");
        }else
        {
            employee_mostrarUno(this);

            funcionContinuarSiONo("\n¿Desea dar de baja a este empleado? s/n ",seguir);

            if(seguir[0]=='n' || seguir[0]=='N')
            {
                printf("\n Baja de empleado cancelada..");

            }else
            {
                ll_remove(pArrayListEmployee, indice);
                estado=OK;
            }
        }
    }



    return estado;
}
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int estado=ERROR;
    int i;
    int contador=0;
    Employee* this;

    if (pArrayListEmployee != NULL)
    {
        employee_mostrarEncabezado();
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            this= (Employee*)ll_get(pArrayListEmployee, i);
            employee_mostrarUno(this);
            contador++;
            if(contador== 500){
                system("pause");
                contador= 0;
            }

        }
        estado=OK;
    }
    return estado;
}
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int estado= ERROR;
    int opcion;
    if(pArrayListEmployee != NULL)
        {

        enteroRango("\n1. Ordenar por id"
                         "\n2. Ordenar por nombre"
                         "\n3. Ordenar por sueldo"
                         "\n4. Ordenar por horas trabajadas"
                         "\n5. Cancelar ordenamiento"
                         "\n\nElija una opcion", &opcion, 1, 5);

        if(opcion >= 1 && opcion <=4){
            printf("\nORDENANDO!\n");
        }

         switch(opcion){
                case 1:

                    ll_sort(pArrayListEmployee, employee_compareById, 1);
                    printf("\nSe ha ordenado por numero id..");
                    break;
                case 2:

                    ll_sort(pArrayListEmployee, employee_compareByName, 1);
                    printf("\nSe ha ordenado por nombre..");
                    break;
                case 3:

                    ll_sort(pArrayListEmployee, Employee_CompareBySueldo, 1 );
                    printf("\nSe ha ordenado por sueldo..");
                    break;
                case 4:

                    ll_sort(pArrayListEmployee, Employee_CompareByHorasTrabajadas, 1 );
                    printf("\nSe ha ordenado por cantidad de horas trabajadas..");
                    break;
                case 5:
                    printf("\nSaliendo..");
                    break;
            }
            estado=OK;

        }else{

            printf("Error! no se pudo realizar el ordenamiento.");
        }
    return estado;
}
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee){
    int estado= ERROR;
    int i;
    FILE* miArchivo= fopen(path,"w");
    if(miArchivo!= NULL && pArrayListEmployee != NULL){

        Employee* this= NULL;
        int id;
        char nombre[TAM_CADENA];
        char empleo[TAM_CADENA];
        int edad;
        int horasTrabajadas;

        //fprintf(miArchivo,"id,nombre,empleo,edad,horasTrabajadas\n");
        for(i=0;i<ll_len(pArrayListEmployee);i++){
            this= ll_get(pArrayListEmployee, i);

            employee_getId(this, &id);
            employee_getNombre(this, nombre);
            employee_getEmpleo(this, empleo);
            employee_getEdad(this, &edad);
            employee_getHorasTrabajadas(this, &horasTrabajadas);

            fprintf(miArchivo,"%d,%s,%s,%d,%d\n", id, nombre, empleo, edad, horasTrabajadas);
        }
        fclose(miArchivo);
        estado= OK;
    }
    return estado;
}
int controller_cargarUltimoId(LinkedList* pArrayListEmployee, int* ultimoId){
    int estado= ERROR;
    int i;
    int idAux;
    if(pArrayListEmployee != NULL && ultimoId != NULL){
        Employee* this;
        for(i=0;i<ll_len(pArrayListEmployee);i++){
            this= ll_get(pArrayListEmployee, i);
            employee_getId(this, &idAux);
            if(idAux >= *ultimoId){
                *ultimoId= idAux;
            }
        }
        estado= OK;
    }
    return estado;
}
