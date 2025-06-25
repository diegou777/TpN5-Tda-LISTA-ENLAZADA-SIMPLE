#include<bits/stdc++.h>
using namespace std ;
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

int buscar_indice(tlista lista, int valor) {
	pnodo i = lista.inicio;
	int posicion = 0;
	
	while (i != NULL) {
		if (i->dato == valor) {
			return posicion;
		}
		i = i->siguiente;
		posicion++;
	}
	
	return -1;
}

int main() {
	tlista lista;
	iniciar_lista(lista);
	
	int datos[] = {15, 8, 22, 10, 5};
	for (int i = 0; i < 5; i++) {
		pnodo nuevo = new tnodo;
		nuevo->dato = datos[i];
		nuevo->siguiente = NULL;
		agregar_final(lista, nuevo);
	}
	
	mostrar_lista(lista);
	
	int buscado;
	cout << "\nIngrese el valor que desea buscar: ";
	cin >> buscado;
	
	int posicion = buscar_indice(lista, buscado);
	
	if (posicion != -1)
		cout << "El valor " << buscado << " se encuentra en la posición lógica " << posicion << "." << endl;
	else
		cout << "El valor " << buscado << " no se encuentra en la lista." << endl;
	
	return 0;
}

