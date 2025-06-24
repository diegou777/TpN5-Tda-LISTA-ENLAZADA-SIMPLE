#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo {
	int dato;
	pnodo siguiente;
};

typedef struct tlista {
	pnodo inicio;
	pnodo final;
	int cantidad;
};


void iniciar_lista(tlista &lista) {
	lista.inicio = NULL;
	lista.final = NULL;
	lista.cantidad = 0;
}

bool es_vacia(tlista lista) {
	return lista.inicio == NULL;
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

void agregar_inicio(tlista &lista, pnodo nuevo) {
	if (es_vacia(lista)) {
		lista.inicio = nuevo;
		lista.final = nuevo;
	} else {
		nuevo->siguiente = lista.inicio;
		lista.inicio = nuevo;
	}
	lista.cantidad++;
}

void agregar_final(tlista &lista, pnodo nuevo) {
	if (es_vacia(lista)) {
		lista.inicio = nuevo;
		lista.final = nuevo;
	} else {
		lista.final->siguiente = nuevo;
		lista.final = nuevo;
	}
	lista.cantidad++;
}

pnodo eliminar_inicio(tlista &lista) {
	pnodo borrado = NULL;
	if (!es_vacia(lista)) {
		borrado = lista.inicio;
		lista.inicio = borrado->siguiente;
		borrado->siguiente = NULL;
		lista.cantidad--;
		
		if (lista.inicio == NULL) {
			lista.final = NULL;
		}
	}
	return borrado;
}

pnodo eliminar_final(tlista &lista) {
	pnodo borrado = NULL, i;
	if (!es_vacia(lista)) {
		if (lista.inicio == lista.final) {
			borrado = lista.inicio;
			lista.inicio = NULL;
			lista.final = NULL;
		} else {
			for (i = lista.inicio; i->siguiente != lista.final; i = i->siguiente);
			borrado = lista.final;
			lista.final = i;
			lista.final->siguiente = NULL;
		}
		lista.cantidad--;
	}
	return borrado;
}

int obtener_cantidad(tlista lista) {
	return lista.cantidad;
}

void mostrar_lista(tlista lista) {
	pnodo i;
	if (!es_vacia(lista)) {
		cout << "Elementos de la lista: ";
		for (i = lista.inicio; i != NULL; i = i->siguiente) {
			cout << i->dato << " ";
		}
		cout << endl;
	} else {
		cout << "Lista vacía" << endl;
	}
}
int main() {
	tlista lista;
	iniciar_lista(lista);
	
	int datos[] = {10, 20, 30};
	for (int i = 0; i < 3; i++) {
		pnodo nuevo = new tnodo;
		nuevo->dato = datos[i];
		nuevo->siguiente = NULL;
		agregar_final(lista, nuevo);
	}
	
	mostrar_lista(lista);
	cout << "Cantidad actual: " << obtener_cantidad(lista) << endl;
	
	pnodo nodoInicio = new tnodo;
	nodoInicio->dato = 5;
	nodoInicio->siguiente = NULL;
	agregar_inicio(lista, nodoInicio);
	
	mostrar_lista(lista);
	cout << "Cantidad actual: " << obtener_cantidad(lista) << endl;
	
	pnodo eliminado = eliminar_final(lista);
	if (eliminado != NULL) {
		cout << "Elemento eliminado del final: " << eliminado->dato << endl;
		delete eliminado;
	}
	
	mostrar_lista(lista);
	cout << "Cantidad actual: " << obtener_cantidad(lista) << endl;
	
	return 0;
}
