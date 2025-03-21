#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();


   for (int i = 1; i <= 10; i++) {
      int* elemento = (int*) malloc(sizeof(int));
      *(elemento) = i;
      pushBack(L, elemento);
   }
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
   int suma = 0;
   int *elemento = first(L);

   while (elemento != NULL) {
      suma += *(elemento);
      elemento = next(L);
   }
   return suma;
}
// 
/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List *L, int elem){
   int *firstElem = first(L);

   while (firstElem != NULL) {
      if (*firstElem == elem) {
         popCurrent(L);
      }
      firstElem = next(L);
   }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
   Stack* aux = create_stack();
   int *dato = top(P1);
   while (dato != NULL) {
      push(aux,dato);
      pop(P1);

      dato = top(P1);
   }
   
   int *dato2 = top(aux);
   while (dato2 != NULL) {
      push(P2,dato2);
      push(P1,dato2);
      pop(aux);

      dato2 = top(aux);
   }
}

/* ./test.sh
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {

   List* ListFront = create_list();
   List* ListBack = create_list();

   for (int i = 0; i != '\0' ;i++) {
      pushBack(ListBack, &cadena[i]); 
      pushFront(ListFront, &cadena[i]);     
   }


   int talla = get_size(ListBack);
   char *palBack = first(ListBack);
   char *palFront = first(ListFront);

   //[ ]

   if (talla % 2 != 0)
      return 0;
   
   for (int k = 0; k < talla; k++) {
      if ((ListFront == ']') && (ListBack == '['))
         return 0;
      if ((ListFront == ')') && (ListBack == '('))
         return 0;
      if ((ListFront == '}') && (ListBack == '{'))
         return 0;

      palBack = next(ListBack);
      palFront = next(ListFront);
   }

   return 1;
}
