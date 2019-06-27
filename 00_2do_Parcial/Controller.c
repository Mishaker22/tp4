#include <stdlib.h>
#include "Funciones.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee){
    int estado= -1;
    FILE* miArchivo;
    miArchivo= fopen (path, "r");
    if(miArchivo != NULL && pArrayListEmployee != NULL){
        ll_clear(pArrayListEmployee);
        estado= parser_EmployeeFromText(miArchivo, pArrayListEmployee);
        fclose(miArchivo);
    }
    return estado;
}

int controller_calcularSueldo(LinkedList* pArrayListEmployee){
    int estado= -1;
    if(pArrayListEmployee != NULL){
        ll_map(pArrayListEmployee, laQueMapea);
        estado= 0;
    }
    return estado;
}


LinkedList* controller_filtrar(LinkedList* pArrayListEmployee){

    LinkedList* listaEmpleadosFiltrados= NULL;
    if(pArrayListEmployee != NULL){
        listaEmpleadosFiltrados= ll_filter(pArrayListEmployee, laQueFiltra);
    }
    return listaEmpleadosFiltrados;
}


int controller_addEmployee(LinkedList* pArrayListEmployee, int* ultimoId){
    int id;
    char nombre[TAM_NOM];
    char empleo[TAM_NOM];
    int edad;
    int horasTrabajadas;

    int estado= -1;
    if(pArrayListEmployee != NULL && ultimoId != NULL){
        pedirCadena("Ingrese el nombre",nombre,TAM_NOM);
        pedirCadena("Ingrese el empleo",empleo,TAM_NOM);
        pedirEnteroPositivo("Ingrese la edad", &edad);
        pedirEnteroPositivo("Ingrese las horas trabajadas", &horasTrabajadas);

        id= *ultimoId;
        id++;
        Employee* this= employee_newParametros(id,nombre,empleo,edad,horasTrabajadas);
        ll_add(pArrayListEmployee, this);
        *ultimoId= id;
        estado= 0;
    }
    return estado;
}


int controller_editEmployee(LinkedList* pArrayListEmployee){
    int estado= -1;
    int id;
    int i;
    int indice= -1;
    int opcion;
    char nombre[TAM_NOM];
    char empleo[TAM_NOM];
    int edad;
    int horasTrabajadas;
    Employee* this;

    if(pArrayListEmployee != NULL){
        pedirEnteroPositivo("Ingrese Id de empleado a modificar", &id);

        for(i=0;i<ll_len(pArrayListEmployee);i++){
            this= (Employee*)ll_get(pArrayListEmployee, i);

            if( this->id == id ){
                indice= i;
                break;
            }
        }
        if(indice != -1){
            do{
                employee_mostrarEncabezado();
                employee_mostrarUno(this);
                pedirEnteroRango("\n1. Modificar nombre"
                                 "\n2. Modificar empleo"
                                 "\n3. Modificar edad"
                                 "\n4. Modificar horas trabajadas"
                                 "\n5. VOLVER al menu anterior"
                                 "\n\nElija una opcion", &opcion, 1, 5);
                estado= 0;
                switch(opcion){
                    case 1:
                        pedirCadena("Ingrese el nuevo nombre", nombre,TAM_NOM);
                        employee_setNombre(this,nombre);
                        printf("\nNombre modificado!");
                        break;
                    case 2:
                        pedirCadena("Ingrese el nuevo empleo", empleo,TAM_NOM);
                        employee_setEmpleo(this,empleo);

                        printf("\nEmpleo modificado!");
                        break;
                    case 3:
                        pedirEnteroPositivo("Ingrese la nueva edad", &edad);
                        employee_setEdad(this, edad);
                        printf("\Edad modificada!");
                        break;
                    case 4:
                        pedirEnteroPositivo("Ingrese la nueva cantidad de horas trabajadas", &horasTrabajadas);
                        employee_setHorasTrabajadas(this, horasTrabajadas);
                        printf("\nHoras modificas!");
                        break;
                }
            }while(opcion != 5);
        }
    }
    return estado;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee){
    int estado= -1;
    int id;
    int idAux;
    int i;
    int indice= -1;
    int opcion;
    Employee* this;
    if (pArrayListEmployee != NULL){
        pedirEnteroPositivo("Ingrese Id de empleado a dar de baja", &id);

        for(i=0;i<ll_len(pArrayListEmployee);i++){
            this= (Employee*)ll_get(pArrayListEmployee, i);
            employee_getId(this, &idAux);
            if( idAux == id ){
                indice= i;
                break;
            }
        }
        if(indice != -1){
            employee_mostrarEncabezado();
            employee_mostrarUno(this);
            pedirEnteroRango("\n1. Dar de baja al empleado"
                             "\n2. CANCELAR\n\nElija una opcion",&opcion,1,2);
            if(opcion==1){
                ll_remove(pArrayListEmployee,indice);
                estado= 0;
            }else{
                estado= 1;
            }
        }
    }
    return estado;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee){
    int estado= -1;
    Employee* this;
    int i;
    int contador= 0;
    if(pArrayListEmployee != NULL){
        employee_mostrarEncabezado();
        for(i=0;i<ll_len(pArrayListEmployee);i++){
            this= (Employee*)ll_get(pArrayListEmployee, i);
            employee_mostrarUno(this);
            contador++;
            if(contador== 500){
                system("pause");
                contador= 0;
            }
        }
        estado= 0;
    }
    return estado;
}

int controller_ListEmployeeSueldo(LinkedList* pArrayListEmployee){
    int estado= -1;
    Employee* this;
    int i;
    int contador= 0;
    if(pArrayListEmployee != NULL){
        employee_mostrarEncabezadoSueldo();
        for(i=0;i<ll_len(pArrayListEmployee);i++){
            this= (Employee*)ll_get(pArrayListEmployee, i);
            employee_mostrarUnoSueldo(this);
            contador++;
            if(contador== 500){
                system("pause");
                contador= 0;
            }
        }
        estado= 0;
    }
    return estado;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee){
    int estado= -1;
    //int opcion;
    if(pArrayListEmployee != NULL){

        ll_sort(pArrayListEmployee, employee_compareByName, 1);
        /*
        pedirEnteroRango("\n1. Ordenar empleado por id"
                         "\n2. Ordenar empleado por nombre"
                         "\n3. CANCELAR"
                         "\n\nElija una opcion", &opcion, 1, 3);
        if(opcion!=3){
            printf("\n\n--ORDENANDO... (puede demorar)--\n");
            switch(opcion){
                case 1:
                    ll_sort(pArrayListEmployee, employee_compareById, 1);
                    break;
                case 2:
                    ll_sort(pArrayListEmployee, employee_compareByName, 1);
                    break;
            }
            printf("\n\n--Ordenamiento Finalizado--\n\n");
        }

        */
        estado= 0;
    }
    return estado;
}


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee){
    int estado= -1;
    int i;
    FILE* miArchivo= fopen(path,"w");
    if(miArchivo!= NULL && pArrayListEmployee != NULL){

        Employee* this= NULL;
        int id;
        char nombre[TAM_NOM];
        char empleo[TAM_NOM];
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
        estado= 0;
    }
    return estado;
}


int controller_cargarUltimoId(LinkedList* pArrayListEmployee, int* ultimoId){
    int estado= -1;
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
        estado= 0;
    }
    return estado;
}
