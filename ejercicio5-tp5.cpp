#include<bits/stdc++.h>
using namespace std;
//5a. estructura de lista enlazada simple
typedef struct tnodo* pnodo;

typedef struct tnodo {
	int dato;
	pnodo siguiente;
};
//5b Ordenaci�n por selecci�n
// Inicializa una lista vac�a
void iniciar_lista(pnodo &lista) {
	lista = NULL;
}

// Agrega un nodo al final
void agregar_final(pnodo &lista, int valor) {
	pnodo nuevo = new tnodo;
	nuevo->dato = valor;
	nuevo->siguiente = NULL;
	
	if (lista == NULL) {
		lista = nuevo;
	} else {
		pnodo i = lista;
		while (i->siguiente != NULL) {
			i = i->siguiente;
		}
		i->siguiente = nuevo;
	}
}

// Muestra la lista
void mostrar_lista(pnodo lista) {
	while (lista != NULL) {
		cout << lista->dato << " -> ";
		lista = lista->siguiente;
	}
	cout << "NULL" << endl;
}
void ordenar_seleccion(pnodo &lista) {
	for (pnodo i = lista; i != NULL; i = i->siguiente) {
		pnodo min = i;
		for (pnodo j = i->siguiente; j != NULL; j = j->siguiente) {
			if (j->dato < min->dato) {
				min = j;
			}
		}
		if (min != i) {
			int temp = i->dato;
			i->dato = min->dato;
			min->dato = temp;
		}
	}
}
//5c. Combinar dos listas
//i M�todo sin importar el orden
pnodo combinar_sin_orden(pnodo l1, pnodo l2) {
	pnodo nueva = NULL;
	while (l1 != NULL) {
		agregar_final(nueva, l1->dato);
		l1 = l1->siguiente;
	}
	while (l2 != NULL) {
		agregar_final(nueva, l2->dato);
		l2 = l2->siguiente;
	}
	return nueva;
}
//ii M�todo respetando el orden ascendente
pnodo combinar_con_orden(pnodo l1, pnodo l2) {
	pnodo resultado = NULL;
	
	while (l1 != NULL && l2 != NULL) {
		if (l1->dato <= l2->dato) {
			agregar_final(resultado, l1->dato);
			l1 = l1->siguiente;
		} else {
			agregar_final(resultado, l2->dato);
			l2 = l2->siguiente;
		}
	}
	
	while (l1 != NULL) {
		agregar_final(resultado, l1->dato);
		l1 = l1->siguiente;
	}
	while (l2 != NULL) {
		agregar_final(resultado, l2->dato);
		l2 = l2->siguiente;
	}
	
	return resultado;
}

