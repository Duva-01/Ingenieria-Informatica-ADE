/*

	Autor: David Martinez Diaz
	
	Grupo: GII-ADE

	Fichero: Ejercicio5(AVL-APO).cpp

*/
//----------------------------------------------------------------//

//a) Insertar en el orden indicado (detallando los pasos) las siguientes
//claves en un AVL: {56, 37, 58, 72, 57, 80, 38, 33, 30}

/*

En primer lugar tenemos este arbol donde no hay que rotar 
si no que simplemente insertamos:

	 56
	/   \
   37   58
  	 	/ \
  	   57 72

Cuando metemos el 80: Rotacion simple izquierda


	 58
	/   \
   56   72
   / \	  \
  37 57    80

Cuando metemos el 38 y el 33: Insertamos normalmente

	 58
	/   \
   56   72
   / \	  \
  37 57    80
  /\  
 33 38  
 
Cuando metemos el 12: Rotacion simple derecha, donde finalmente queda
este arbol AVL

	  58
	/   \
   37   72
   / \	  \
  33 56    80
  /   /\
30	 38 57

//--------------------------------------------------------------------//
//--------------------------------------------------------------------//
//--------------------------------------------------------------------//

b) Insertar los elementos anteriores en el orden indicado (detallando los pasos) en un
APO. Borrar un elemento.

En primer lugar que cuando insertamos 37 se cambian de lugar con la raiz 
y el 58,72, 57 y el 80 entra normalmente:

	 37
	/   \
   56    58
   / \	 /
  72 57 80

Luego cuando metemos el 38, este se cambia de posicion con el 58:

	 37
	/   \
   56    38
   / \	 / \
  72 57 80  58

Luego cuando metemos el 33, este se cambia de posicion hasta llegar a la raiz:

	 33
	/   \
   37    38
   / \	 / \
  56 57 80  58
  /
72

Luego cuando metemos el 30, este se cambia de posicion hasta llegar a la raiz:

  	  30
	/   \
   33    38
   / \	 / \
  37 57 80  58
  / \
72   56

Quedando asi el APO antes de eliminar un elemento: voy a eliminar la raiz el 30.

 	  56
	/   \
   33    38
   / \	 / \
  37 57 80  58
  / 
72   

Y voy sustituyendo por el valor mas pequeño:

 	  33
	/   \
   37    38
   / \	 / \
  56 57 80  58
  /
72

*/
