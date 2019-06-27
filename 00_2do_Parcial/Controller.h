#ifndef CONTROLLER_H_INCLUDED
#include "LinkedList.h"

#define CONTROLLER_H_INCLUDED
#endif // CONTROLLER_H_INCLUDED


/** \brief Función que carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* El puntero a la ruta del archivo
 * \param pArrayListEmployee LinkedList* El puntero a la lista de empleados
 * \return int Devuelve 0 si se pudieron cargar los datos, o -1 si no se cargaron
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);





/** \brief Función que da de alta un empleado en la lista de empleados
 *
 * \param pArrayListEmployee LinkedList* El puntero a la lista de empleados
 * \return int Devuelve 0 si se pudo dar el alta, o -1 si no se pudo
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* ultimoId);


/** \brief Función que edita un empleado de la lista de empleados
 *
 * \param pArrayListEmployee LinkedList* El puntero a a la lista de empleados
 * \return int Devuelve 0 si se pudo editar, o -1 si no se pudo
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);


/** \brief Función que da de baja un empleado de la lista de empleados
 *
 * \param pArrayListEmployee LinkedList* El puntero a la lista de empleados
 * \return int Devuelve 0 si se pudo realizar la baja, o -1 si no se pudo
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);


/** \brief Función que lista los empleados de la lista
 *
 * \param pArrayListEmployee LinkedList* El puntero a la lista de empleados
 * \return int Devuelve 0 si se pudo listar, o -1 si no se pudo
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);




int controller_ListEmployeeSueldo(LinkedList* pArrayListEmployee);



/** \brief Función que ordena empleados de una lista
 *
 * \param pArrayListEmployee LinkedList* El puntero a la lista de empleados
 * \return int Devuelve 0 si se pudo ordenar, o -1 si no se pudo
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);


/** \brief Función que guarda la lista de empleados en un archivo en modo texto
 *
 * \param path char* El puntero a la ruta del archivo
 * \param pArrayListEmployee LinkedList* El puntero a la lista de empleados
 * \return int Devuelve 0 si se pudo guardar, o -1 si no se pudo
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);




/** \brief Función que obtiene el ultimo id de la lista de empleados
 *
 * \param pArrayListEmployee LinkedList* El puntero a la lista de empleados
 * \param ultimoId int* El puntero al último id
 * \return int Devuelve 0 si se pudo obtener el último id, o -1 si no se pudo
 *
 */
int controller_cargarUltimoId(LinkedList* pArrayListEmployee, int* ultimoId);


int controller_listEmployeeSueldo(LinkedList* pArrayListEmployee);

int controller_calcularSueldo(LinkedList* pArrayListEmployee);

LinkedList* controller_filtrar(LinkedList* pArrayListEmployee);
