#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);
static void swap(LinkedList* this, int, int);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void){
    LinkedList* this;
    this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this != NULL){
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this){
    int returnAux = -1;

    if (this != NULL){
        returnAux= this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex){
    int contador= 1;
    Node* pNode = NULL;

    if (this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)){
        pNode= this->pFirstNode;
        while(contador <= nodeIndex){
            pNode= pNode->pNextNode;
            contador++;
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex){
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement){
    int returnAux = -1;
    Node* nuevoNodo;
    Node* nodoAnterior;
    Node* nodoSiguiente= NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)){
        nuevoNodo= (Node*)malloc(sizeof(Node));
        nuevoNodo->pElement= pElement;
        nuevoNodo->pNextNode= NULL;

        //Si no habia nodos en la lista:
        if(ll_len(this) == 0 && nodeIndex== 0){  //El nodo es el primer nodo de la lista
            this->pFirstNode= nuevoNodo;

        //Si el nodo se inserta en el lugar del primer nodo:
        }else if(ll_len(this) > 0 && nodeIndex== 0){
            nodoSiguiente= getNode(this, nodeIndex);
            this->pFirstNode= nuevoNodo;
            nuevoNodo->pNextNode= nodoSiguiente;

        //Si el nodo se inserta en otro lugar (incluido el nodeIndex == size)
        }else if(ll_len(this) > 0 && nodeIndex > 0){
            nodoAnterior= getNode(this, nodeIndex - 1);
            nodoSiguiente= getNode(this, nodeIndex);
            nodoAnterior->pNextNode= nuevoNodo;
            nuevoNodo->pNextNode= nodoSiguiente;
        }

        this->size++;
        returnAux= 0;
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement){
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement){
    int returnAux = -1;
    int indice;
    if (this != NULL){
        indice= ll_len(this);
        addNode(this, indice, pElement);
        returnAux= 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index){

    void* returnAux = NULL;
    void* pElement;

    if(this != NULL && index >= 0 && index < ll_len(this)){
        if(this->size > 0){
            pElement= (getNode(this, index))->pElement;
            if(pElement != NULL){
                returnAux= pElement;
            }
        }
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement){
    int returnAux = -1;
    Node* unNodo;

    //Probar con un index == ll_len(this)
    if(this != NULL && index >= 0 && index < ll_len(this)){

        if( ll_isEmpty(this) || index == ll_len(this)){
            ll_add(this, pElement);
        }else{
            unNodo= getNode(this, index);
            unNodo->pElement= pElement;
        }
        returnAux= 0;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index){
    int returnAux = -1;
    Node* nodoAnterior;
    Node* nodoBorrar;

    if(this != NULL && ll_len(this) > 0 && index >= 0 && index < ll_len(this)){

        //Si se elimina el primer nodo
        if(index== 0){
            nodoBorrar= getNode(this,index);
            this->pFirstNode= nodoBorrar->pNextNode;
        }else{
            nodoBorrar= getNode(this, index);
            nodoAnterior= getNode(this, index - 1);
            nodoAnterior->pNextNode= nodoBorrar->pNextNode;
        }

        free(nodoBorrar);
        nodoBorrar= NULL;
        this->size--;

        returnAux= 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this){
    int returnAux = -1;
    int indice;

    if(this!= NULL){

        if(ll_len(this) > 0){

            indice= ll_len(this) - 1;
            do{
                ll_remove(this, indice);
                indice--;
            }while(indice>=0);
        }
        returnAux= 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this){
    int returnAux = -1;
    if(this != NULL){
        ll_clear(this);
        free(this);
        this=NULL;
        returnAux= 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement){
    int returnAux = -1;
    int i;
    Node* unNodo;
    if(this != NULL && ll_len(this) > 0){

        for(i=0; i<ll_len(this); i++){
            unNodo= getNode(this, i);
            if(unNodo->pElement == pElement){
                returnAux= i;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this){
    int returnAux = -1;

    if(this != NULL){
        if(ll_len(this) == 0){
            returnAux= 1;
        }else{
            returnAux= 0;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement){
    int returnAux = -1;

    //Probar con index == ll_len(this)
    if(this!=NULL && index >= 0 && index <= ll_len(this)){
        returnAux= addNode(this, index, pElement);
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index){
    void* returnAux = NULL;
    if(this!=NULL && index >= 0 && index < ll_len(this)){
        returnAux= ll_get(this,index);
        ll_remove(this,index);
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement){
    int returnAux = -1;
    if(this != NULL){
        if(ll_indexOf(this, pElement)>=0){
            returnAux= 1;
        }else{
            returnAux= 0;
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2){
    int returnAux = -1;
    //int i= 0;
    int indice= 0;
    void* e1;
    void* e2;
    if(this!= NULL && this2!= NULL){

        //Supongo que las listas son iguales
        returnAux= 1;

        if( ll_len(this) != ll_len(this2) ){
            //No tienen el mismo tamaño por ende no son iguales
            returnAux= 0;
        }else{
            do{
                e1= ll_get(this, indice);
                e2= ll_get(this2, indice);
                if(e1 != e2){
                    //Al menos un elemento no es igual
                    returnAux= 0;
                    break;
                }
                indice++;
            }while(indice < ll_len(this));
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this, int from, int to){
    LinkedList* cloneArray = NULL;
    void* unElemento;
    int indice;
    if(this!=NULL){

        //Probar con un to == ll_len(lista)
        if( !(from < 0 || to > ll_len(this) || to < from) ){
           cloneArray= ll_newLinkedList();
           for(indice= from; indice <= to; indice++){
                //unElemento= malloc(sizeof(Node));
                unElemento= ll_get(this, indice);
                ll_add(cloneArray, unElemento);
           }
        }
    }
    return cloneArray;
}


/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this){

    LinkedList* cloneArray = NULL;
    int tamanio;
    if (this != NULL){
        tamanio= ll_len(this);
        cloneArray= ll_subList(this, 0, tamanio);
    }
    return cloneArray;
}


/** \brief Función que intercambia los elementos de dos nodos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param int El indice de un nodo de la lista
 * \param int El indice de otro nodo de la lista
 * \return void
 *
 */
static void swap(LinkedList* this, int i, int j){

    void* dato;

    dato= getNode(this,i)->pElement;
    ll_set(this, i, (getNode(this,j)->pElement) );
    ll_set(this, j, dato);
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order){

    int returnAux =-1;
    int i;
    int j;

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1 )){

        for(i=0;i<this->size-1;i++){
            for(j=i+1;j<this->size;j++){

                //Orden ascendente
                if(order == 1 && pFunc(getNode(this,i)->pElement, getNode(this,j)->pElement) > 0){
                    swap(this,i,j);
                }

                //Orden descendente
                if(order == 0 && pFunc(getNode(this,i)->pElement, getNode(this,j)->pElement) < 0){
                    swap(this,i,j);
                }
            }
        }
        returnAux= 0;
    }
    return returnAux;

}

int ll_map(LinkedList* this, int (*pFunc)(void* emp) ){
    int retorno = -1;
    int i;

    if(this != NULL && pFunc != NULL){
        for(i=0; i<ll_len(this); i++){
            pFunc(ll_get(this, i));
        }
        retorno = 0;
    }
    return retorno;
}

LinkedList* ll_filter(LinkedList* this, int(*pFunc)(void*)){
    LinkedList* retorno = NULL;
    int i;
    int flag= -1;
    if(this != NULL && pFunc != NULL){
        for(i=0; i<ll_len(this); i++){
            if(pFunc(ll_get(this, i)) == 0){
                if(flag == -1){
                    retorno= ll_newLinkedList();
                    flag= 0;
                }
                ll_add(retorno, ll_get(this, i));
            }
        }
    }
    return retorno;
}

