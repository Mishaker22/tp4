#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#endif // FUNCIONES_H_INCLUDED

/** \brief Función que solicita un número entero positivo y lo valida
 *
 * \param char[] Lo que representa el número que se solicita
 * \param int* El puntero al número
 * \return int Devuelve 0 si se pudo cargar, o -1 si no se pudo
 *
 */
int pedirEnteroPositivo(char[], int*);


/** \brief Función que solicita un número entero dentro de un rango y lo valida
 *
 * \param char[] Lo que representa el número que se solicita
 * \param int* El puntero al número
 * \param int Número menor admitido
 * \param int Número mayor admitido
 * \return int Devuelve 0 si se pudo cargar, o -1 si no se pudo
 *
 */
int pedirEnteroRango(char[], int*, int, int);


/** \brief Función que valida el tamaño de una cadena
 *
 * \param char[] Lo que representa la cadena
 * \param char* El puntero a la cadena validada según el tamaño
 * \param int Tamaño máximo de caracteres -1
 * \return int Devuelve 0 si se pudo validar, o -1 si no se pudo
 *
 */
int validarTamCadena(char[], char*, int);


/** \brief Función que solicita una cadena y la valida según el tamaño
 *
 * \param char[] Lo que representa la cadena
 * \param char* El puntero a la cadena validada según el tamaño
 * \param int Tamaño máximo de caracteres -1
 * \return int Devuelve 0 si se pudo validar, o -1 si no se pudo
 *
 */
int pedirCadena(char[], char*, int);

