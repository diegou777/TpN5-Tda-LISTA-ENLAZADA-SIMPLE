#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo {
	int dato;
	pnodo siguiente;
};


void iniciar_lista(pnodo &lista) {
	lista = NULL;
}

bool es_vacia(pnodo lista) {
	return lista == NULL;
}

void crear_nodo(pnodo &nuevo) {
	nuevo = new tnodo;
	if (nuevo != NULL) {
		cout << "Ingrese valor: ";
		cin >> nuevo->dato;
		nuevo->siguiente = NULL;
	} else {
		cout << "Memoria insuficiente" << endl;
	}
}

void agregar_inicio(pnodo &lista, pnodo nuevo) {
	nuevo->siguiente = lista;
	lista = nuevo;
}

void agregar_final(pnodo &lista, pnodo nuevo) {
	pnodo i;
	if (lista == NULL) {
		lista = nuevo;
	} else {
		for (i = lista; i->siguiente != NULL; i = i->siguiente);
		i->siguiente = nuevo;
	}
}

void agregar_ordenado(pnodo &lista, pnodo nuevo) {
	pnodo i;
	if (lista == NULL) {
		lista = nuevo;
	} else {
		if (nuevo->dato < lista->dato) {
			nuevo->siguiente = lista;
			lista = nuevo;
		} else {
			for (i = lista; i->siguiente != NULL && nuevo->dato > i->siguiente->dato; i = i->siguiente);
			nuevo->siguiente = i->siguiente;
			i->siguiente = nuevo;
		}
	}
}

pnodo eliminar_inicio(pnodo &lista) {
	pnodo borrado;
	if (lista == NULL) {
		borrado = NULL;
	} else {
		borrado = lista;
		lista = lista->siguiente;
		borrado->siguiente = NULL;
	}
	return borrado;
}

pnodo eliminar_final(pnodo &lista) {
	pnodo borrado, i;
	if (lista == NULL) {
		borrado = NULL;
	} else if (lista->siguiente == NULL) {
		borrado = lista;
		lista = NULL;
	} else {
		for (i = lista; i->siguiente->siguiente != NULL; i = i->siguiente);
		borrado = i->siguiente;
		i->siguiente = NULL;
	}
	return borrado;
}

pnodo eliminar_nodo(pnodo &lista, int valor) {
	pnodo borrado, i;
	if (lista == NULL) {
		borrado = NULL;
	} else if (lista->dato == valor) {
		borrado = lista;
		lista = borrado->siguiente;
		borrado->siguiente = NULL;
	} else {
		for (i = lista; i->siguiente != NULL && valor != i->siguiente->dato; i = i->siguiente);
		if (i->siguiente != NULL) {
			borrado = i->siguiente;
			i->siguiente = borrado->siguiente;
			borrado->siguiente = NULL;
		} else {
			borrado = NULL;
		}
	}
	return borrado;
}

void mostrar_lista(pnodo lista) {
	pnodo i;
	if (lista != NULL) {
		for (i = lista; i != NULL; i = i->siguiente) {
			cout << "Nodo: " << i->dato << endl;
		}
	} else {
		cout << "Lista vacía" << endl;
	}
}

bool buscar_nodo(pnodo lista, int valor) {
	pnodo i;
	bool encontrado = false;
	for (i = lista; i != NULL && !encontrado; i = i->siguiente) {
		if (i->dato == valor) {
			encontrado = true;
		}
	}
	return encontrado;
}

pnodo minimo(pnodo &lista) {
	if (lista == NULL) return NULL;
	
	pnodo minNodo = lista;
	pnodo antMin = NULL;
	pnodo i = lista;
	pnodo anterior = NULL;
	
	while (i != NULL) {
		if (i->dato < minNodo->dato) {
			minNodo = i;
			antMin = anterior;
		}
		anterior = i;
		i = i->siguiente;
	}
	
	if (antMin == NULL) {
		lista = minNodo->siguiente;
	} else {
		antMin->siguiente = minNodo->siguiente;
	}
	
	minNodo->siguiente = NULL;
	return minNodo;
}

int main() {
	pnodo lista;
	iniciar_lista(lista);
	int valores[] = {20, 5, 12, 3, 17};
	for (int i = 0; i < 5; i++) {
		pnodo nuevo = new tnodo;
		nuevo->dato = valores[i];
		nuevo->siguiente = NULL;
		agregar_final(lista, nuevo);
	}
	
	cout << "Lista original:" << endl;
	mostrar_lista(lista);
	
	pnodo menor = minimo(lista);
	if (menor != NULL) {
		cout << "\nNodo mínimo extraído: " << menor->dato << endl;
		delete menor;
	}
	cout << "\nLista actualizada:" << endl;
	mostrar_lista(lista);
	
	return 0;
}

