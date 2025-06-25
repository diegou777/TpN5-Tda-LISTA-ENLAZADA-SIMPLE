#include<bits/stdc++.h>
using namespace std;

typedef struct tnodo* pnodo;

typedef struct tnodo {
	int dato;
	pnodo siguiente;
};

typedef struct {
	pnodo frente;
	pnodo final;
	int cantidad;
} Cola;

void iniciar_cola(Cola &c) {
	c.frente = NULL;
	c.final = NULL;
	c.cantidad = 0;
}

bool es_cola_vacia(Cola c) {
	return c.frente == NULL;
}

void encolar(Cola &c, int valor) {
	pnodo nuevo = new tnodo;
	nuevo->dato = valor;
	nuevo->siguiente = NULL;
	
	if (es_cola_vacia(c)) {
		c.frente = nuevo;
		c.final = nuevo;
	} else {
		c.final->siguiente = nuevo;
		c.final = nuevo;
	}
	
	c.cantidad++;
}

int desencolar(Cola &c) {
	if (es_cola_vacia(c)) {
		cout << "Cola vac�a. No se puede desencolar." << endl;
		return -999;
	}
	
	pnodo aux = c.frente;
	int valor = aux->dato;
	c.frente = aux->siguiente;
	
	if (c.frente == NULL) {
		c.final = NULL;
	}
	
	delete aux;
	c.cantidad--;
	return valor;
}

int obtener_frente(Cola c) {
	if (es_cola_vacia(c)) {
		cout << "Cola vac�a. No hay frente." << endl;
		return -999;
	}
	return c.frente->dato;
}

int cantidad_elementos(Cola c) {
	return c.cantidad;
}

void mostrar_cola(Cola c) {
	pnodo i = c.frente;
	while (i != NULL) {
		cout << i->dato << " -> ";
		i = i->siguiente;
	}
	cout << "NULL" << endl;
}


