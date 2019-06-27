#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include <stdio.h>
#include "LinkedList.h"

#endif // PARSER_H_INCLUDED


/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE* El puntero al archivo
 * \param pArrayListEmployee LinkedList El puntero a la lista de empleados
 * \return int Devuelve 0 si se pudo parsear el archivo, o -1 si no se pudo
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
