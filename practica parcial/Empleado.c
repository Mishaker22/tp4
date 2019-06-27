#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"

Employee* employee_new()
{
    Employee* this;
    this=(Employee*) malloc(sizeof(Employee));
    return this;
}
Employee* employee_newParametros(int id, char* nombre, char* empleo, int edad, int horasTrabajadas){
    Employee* this= employee_new();
    if(this != NULL){

        employee_setId(this, id);
        employee_setNombre(this, nombre);
        employee_setEmpleo(this, empleo);
        employee_setEdad(this, edad);
        employee_setHorasTrabajadas(this, horasTrabajadas);

        //laQueMapea(this);
    }
    return this;
}
int employee_setId(Employee* this, int id){
    int estado= -1;
    if(this != NULL){
        this-> id= id;
        estado= 0;
    }
    return estado;
}

int employee_getId(Employee* this,int* id){
    int estado= -1;
    if(this != NULL){
        *id= this->id;
        estado= 0;
    }
    return estado;
}

int employee_setNombre(Employee* this, char* nombre){
    int estado= -1;
    if(this != NULL && nombre != NULL){
        strcpy(this->nombre,nombre);
        estado= 0;
    }
    return estado;
}
int employee_getNombre(Employee* this, char* nombre){
    int estado= -1;
    if(this != NULL && nombre != NULL){
        strcpy(nombre, this->nombre);
        estado= 0;
    }
    return estado;
}


int employee_setEmpleo(Employee* this, char* empleo){
    int estado= -1;
    if(this != NULL && empleo != NULL){
        strcpy(this->empleo,empleo);
        estado= 0;
    }
    return estado;
}
int employee_getEmpleo(Employee* this, char* empleo){
    int estado= -1;
    if(this != NULL && empleo != NULL){
        strcpy(empleo, this->empleo);
        estado= 0;
    }
    return estado;
}


int employee_setEdad(Employee* this, int edad){
    int estado= -1;
    if(this != NULL){
        this->edad= edad;
        estado= 0;
    }
    return estado;
}

int employee_getEdad(Employee* this, int* edad){
    int estado= -1;
    if(this != NULL && edad != NULL){
        *edad= this->edad;
        estado= 0;
    }
    return estado;
}


int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas){
    int estado= -1;
    if(this != NULL){
        this->horasTrabajadas= horasTrabajadas;
        estado= 0;
    }
    return estado;
}
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas){
    int estado= -1;
    if(this != NULL && horasTrabajadas != NULL) {
        *horasTrabajadas= this->horasTrabajadas;
        estado= 0;
    }
    return estado;
}

int employee_setSueldo(Employee* this, int sueldo){
    int estado= -1;
    if(this != NULL){
        this->sueldo= sueldo;
    }
    return estado;
}
int employee_getSueldo(Employee* this, int* sueldo){
    int estado= -1;
    if(this != NULL){
        *sueldo= this->sueldo;
    }
    return estado;
}
int employee_compareById(void* emp1, void* emp2)
{
    Employee* e1 = (Employee*) emp1;
    Employee* e2 = (Employee*) emp2;
    int id1;
    int id2;
    employee_getId(e1, &id1);
    employee_getId(e2, &id2);
    int retorno;

    if( id1 > id2 ){
        retorno= 1;
    }else if( id1 < id2 ){
        retorno= -1;
    }else{
        retorno= 0;
    }
    return retorno;
}
int employee_compareByName(void* emp1, void* emp2)
{
    Employee* e1 = (Employee*) emp1;
    Employee* e2 = (Employee*) emp2;
    char nombre1[TAM_CADENA];
    char nombre2[TAM_CADENA];

    employee_getNombre(e1, nombre1);
    employee_getNombre(e2, nombre2);
    return stricmp(nombre1,nombre2);
}
int Employee_CompareByHorasTrabajadas(void* emp1, void*emp2)
{
    Employee* e1 = (Employee*) emp1;
    Employee* e2 = (Employee*) emp2;
    int horasTrabajadas1;
    int horasTrabajadas2;
    employee_getHorasTrabajadas(e1, &horasTrabajadas1);
    employee_getHorasTrabajadas(e2, &horasTrabajadas2);
    int retorno;

    if( horasTrabajadas1 > horasTrabajadas2 ){
        retorno= 1;
    }else if( horasTrabajadas1 < horasTrabajadas2 ){
        retorno= -1;
    }else{
        retorno= 0;
    }
    return retorno;
}
int Employee_CompareBySueldo(void* emp1, void*emp2)
{
    Employee* e1 = (Employee*) emp1;
    Employee* e2 = (Employee*) emp2;
    int sueldo1;
    int sueldo2;
    employee_getId(e1, &sueldo1);
    employee_getId(e2, &sueldo2);
    int retorno;

    if( sueldo1 > sueldo2 ){
        retorno= 1;
    }else if( sueldo1 < sueldo2 ){
        retorno= -1;
    }else{
        retorno= 0;
    }
    return retorno;
}
void employee_mostrarEncabezado(){
    printf("\n\tID\t\t\tNOMBRE \t\t\tEMPLEO \t\tEDAD \t\tHORAS TRABAJADAS\n\n");
}
void employee_mostrarUno(Employee* this)
{
    int id;
    char nombre[TAM_CADENA];
    char empleo[TAM_CADENA];
    int edad;
    int horasTrabajadas;

    employee_getId(this, &id);
    employee_getNombre(this, nombre);
    employee_getEmpleo(this, empleo);
    employee_getEdad(this, &edad);
    employee_getHorasTrabajadas(this, &horasTrabajadas);


    if(this != NULL){
        printf("\t%2d \t%22s \t%22s  \t%d \t\t%d\n", id, nombre, empleo, edad, horasTrabajadas);
    }
}
