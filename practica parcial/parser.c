#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "parser.h"

#define TAM_BUFFER 500

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int estado = -1;
    int cantidad;

    if(pFile != NULL && pArrayListEmployee != NULL){
        Employee* this;
        char id[TAM_BUFFER], nombre[TAM_BUFFER], empleo[TAM_BUFFER], edad[TAM_BUFFER], horasTrabajadas[TAM_BUFFER];

        //fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,empleo,edad,horasTrabajadas);

        do{
            cantidad= fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,empleo,edad,horasTrabajadas);
            if (cantidad == 5){
                this = (Employee*)malloc(sizeof(Employee));
                employee_setId(this, atoi(id));
                employee_setNombre(this, nombre);
                employee_setEmpleo(this, empleo);
                employee_setEdad(this, atoi(edad));
                employee_setHorasTrabajadas(this, atoi(horasTrabajadas));
                ll_add(pArrayListEmployee, this);
            }else{
                break;
            }
        }while(!feof(pFile));
        estado= 0;
    }
    return estado;
}
