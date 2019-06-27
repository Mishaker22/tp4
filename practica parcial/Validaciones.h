
/** \brief funcion que valida si es numero
 *
 * \param  letra
 * \param
 * \return 1 cuando son numeros 0 cuando no lo som
 *
 */

int funcionEsNum(char letra[]);
/** \brief funcion que valida si son numeros
 *
 * \param  char mensaje
 * \param input
 * \return 0 si realizo la funcion
 *
 */

int funcionGetStringNumeros(char mensaje[],char input[]);
/** \brief funcion que valida que sean letras y no numeros
 *
 * \param char letra
 * \param
 * \return 0 si lo son 1 si no lo son
 *
 */

int funcionSoloLetras(char letra[]);
/** \brief funcion que valida que sean letras y no numeros
 *
 * \param char letra
 * \param
 * \return 1 si lo son 0 si no lo son
 *
 */
int funcionGetStringLetras(char msj[],char input[]);
/** \brief funcion que valida si desea continuar o no
 *
 * \param mensaje char
 * \param char input
 * \return ninguna
 *
 */

void funcionContinuarSiONo(char mensaje[],char input[]);
/** \brief pide enteros positivos y valida que los ean
 *
 * \param mensaje
 * \param
 * \return 0 si lo relizo
 *
 */

int pedirEnteroPositivo(char mensaje[], int* pInt);
/** \brief valida un rango escogido
 *
 * \param mensjae char
 * \param minimo del array y maximo
 * \return 0 si realiza 1 si no
 *
 */

int enteroRango(char mensaje[], int* pInt, int minimo, int maximo);
/** \brief valida tamaño de la cadena que no se pase
 *
 * \param mensaje char cadena char
 * \param tamaño array
 * \return nada
 *
 */

void validarTamCadena(char mensaje[], char cadena[], int tam);
/** \brief pide cadena solo letras y nuemros
 *
 * \param mensaje cadena char
 * \param tamaño del array
 * \return nada
 *
 */

int pedirCadena(char mensaje[], char* pCadena, int tam);
/** \brief valida dato escogido
 *
 * \param minimo array y maximo
 * \param mensaje
 * \return 0 si realiza
 *
 */

int validarDato(char mensaje[], int minimo, int maximo);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
 int menu();

