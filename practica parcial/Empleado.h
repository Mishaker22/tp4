#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#define TAM_CADENA 128
typedef struct
{
    int id;
    char nombre[TAM_CADENA];
    char empleo[TAM_CADENA];
    int horasTrabajadas;
    int sueldo;
    int edad;


}Employee;
#endif // employee_H_INCLUDED


/** \brief Funci�n que muestra un encabezado de empleado
 *
 * \return void
 *
 */
void employee_mostrarEncabezado();


/** \brief Funci�n que muestra los datos de un empleado
 *
 * \param Employee* El puntero al empleado
 * \return void
 *
 */
void employee_mostrarUno(Employee*);


/** \brief Constructor por defecto de empleado. Crea un empleado en memoria dinamica
 *
 * \return Employee* Devuelve el puntero al empleado creado
 *
 */
Employee* employee_new();


/** \brief Constructor parametrizado de empleado. Crea un empleado en memoria dinamica
           con los datos recibidos como parametros
 *
 * \param id int El id del empleado
 * \param nombre char* El nombre del empleado
 * \param empleo char* El empleo del empleado
 * \param edad int El edad del empleado
 * \param horasTrabajadas int Las horas trabajadas del empleado
 * \return Employee* Devuelve el puntero al empleado creado
 *
 */
Employee* employee_newParametros(int id, char* nombre, char* empleo, int edad, int horasTrabajadas);


/** \brief Funci�n que setea el id de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param id int El id a setear
 * \return int Devuelve 0 si se pudo setear, o -1 si no se pudo
 *
 */
int employee_setId(Employee* this,int id);


/** \brief Funci�n que obtiene el id de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param id int* El id obtenido
 * \return int Devuelve 0 si se pudo obtener, o -1 si no se pudo
 *
 */
int employee_getId(Employee* this,int* id);


/** \brief Funci�n que setea el nombre de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param nombre char* El nombre a setear
 * \return int Devuelve 0 si se pudo setear, o -1 si no se pudo
 *
 */
int employee_setNombre(Employee* this,char* nombre);


/** \brief Funci�n que obtiene el nombre de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param nombre char* El nombre obtenido
 * \return int Devuelve 0 si se pudo setear, o -1 si no se pudo
 *
 */
int employee_getNombre(Employee* this,char* nombre);


/** \brief Funci�n que setea el EMPLEO de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param nombre char* El EMPLEO a setear
 * \return int Devuelve 0 si se pudo setear, o -1 si no se pudo
 *
 */

int employee_setEmpleo(Employee* this,char* empleo);
/** \brief Funci�n que obtiene el EMPLEO de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param nombre char* El EMPLEO obtenido
 * \return int Devuelve 0 si se pudo setear, o -1 si no se pudo
 *
 */
int employee_getEmpleo(Employee* this,char* empleo);




/** \brief Funci�n que setea las horas trabajadas de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param horasTrabajadas int Las horas trabajadas a setear
 * \return int Devuelve 0 si se pudo setear, o -1 si no se pudo
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);


/** \brief Funci�n que obtiene las horas trabajadas de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param horasTrabajadas int* Las horas obtenidas
 * \return int Devuelve 0 si se pudo obtener, o -1 si no se pudo
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);


/** \brief Funci�n que setea el edad de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param edad int El edad a setear
 * \return int Devuelve 0 si se pudo setear, o -1 si no se pudo
 *
 */
int employee_setEdad(Employee* this,int edad);


/** \brief Funci�n que obtiene el edad de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param edad int* El edad a obtener
 * \return int Devuelve 0 si se puedo obtener, o -1 si no se pudo
 *
 */
int employee_getEdad(Employee* this,int* edad);





/** \brief Funci�n que compara dos empleados por su nombre
 *
 * \param void* El puntero a un empleado
 * \param void* El puntero a otro empleado
 * \return int Devuelve -1, 0 o 1 seg�n el orden de los empleados
 *
 */
int employee_compareByName(void*, void*);

/** \brief Funci�n que compara dos empleados por id
 *
 * \param void* El puntero a un empleado
 * \param void* El puntero a otro empleado
 * \return int Devuelve -1, 0 o 1 seg�n el orden de los empleados
 *
 */
int employee_compareById(void*, void*);

/** \brief Funci�n que compara dos empleados por edad
 *
 * \param void* El puntero a un empleado
 * \param void* El puntero a otro empleado
 * \return int Devuelve -1, 0 o 1 seg�n el orden de los empleados
 *
 */
int employee_compareByedad(void*, void*);

/** \brief Funci�n que compara dos empleados por horas trabajadas
 *
 * \param void* El puntero a un empleado
 * \param void* El puntero a otro empleado
 * \return int Devuelve -1, 0 o 1 seg�n el orden de los empleados
 *
 */
int employee_compareByHorasTrabajadas(void*, void*);

int laQueMapea(void*);
int laQueFiltra(void*);



/** \brief Funci�n que obtiene el SUELDO de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param nombre char* El SUELDO obtenido
 * \return int Devuelve 0 si se pudo setear, o -1 si no se pudo
 *
 */
int employee_getSueldo(Employee* this, int* sueldo);
/** \brief Funci�n que setea EL SUELDO de un empleado
 *
 * \param this Employee* El puntero al empleado
 * \param horasTrabajadas int EL SUELDO a setear
 * \return int Devuelve 0 si se pudo setear, o -1 si no se pudo
 *
 */
int employee_setSueldo(Employee* this, int sueldo);
/** \brief Funci�n que muestra los datos de un empleado
 *
 * \param Employee* El puntero al empleado
 * \return void
 *
 */
int Employee_CompareBySueldo(void* emp1, void*emp2);
int Employee_CompareByHorasTrabajadas(void* emp1, void*emp2);
void employee_mostrarEncabezadoSueldo();
void employee_mostrarUnoSueldo(Employee* this);
