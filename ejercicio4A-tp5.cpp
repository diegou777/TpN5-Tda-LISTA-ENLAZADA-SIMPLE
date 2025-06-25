#include<bits/stdc++.h>
using namespace std;

typedef struct tnodo* pnodo;

typedef struct tnodo {
	int dato;
	pnodo siguiente;
};

typedef struct {
	pnodo tope;
} Pila;

void iniciar_pila(Pila &p) {
	p.tope = NULL;
}

bool pila_vacia(Pila p) {
	return p.tope == NULL;
}

void push_pila(Pila &p, int valor) {
	pnodo nuevo = new tnodo;
	nuevo->dato = valor;
	nuevo->siguiente = p.tope;
	p.tope = nuevo;
}

int pop_pila(Pila &p) {
	if (pila_vacia(p)) {
		cout << "Pila vacía. No se puede desapilar." << endl;
		return -999;
	}
	
	pnodo aux = p.tope;
	int valor = aux->dato;
	p.tope = aux->siguiente;
	delete aux;
	return valor;
}

void mostrar_pila(Pila p) {
	pnodo i = p.tope;
	while (i != NULL) {
		cout << i->dato << " -> ";
		i = i->siguiente;
	}
	cout << "NULL" << endl;
}




