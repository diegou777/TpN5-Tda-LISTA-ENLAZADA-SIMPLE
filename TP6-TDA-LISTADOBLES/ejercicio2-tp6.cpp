#include <iostream>
using namespace std;

typedef struct tnodo* pnodo;
typedef struct tnodo {
	int dato;
	pnodo sig;
	pnodo ant;
};

typedef struct tlista {
	pnodo inicio;
	pnodo fin;
};

void IniciarLista(tlista &lista) {
	lista.inicio = NULL;
	lista.fin = NULL;
}

void CrearNodo(pnodo &nuevo, int valor) {
	nuevo = new tnodo;
	if (nuevo != NULL) {
		nuevo->dato = valor;
		nuevo->sig = NULL;
		nuevo->ant = NULL;
	}
}

void AgregarInicio(tlista &lista, pnodo nuevo) {
	if (lista.inicio == NULL) {
		lista.inicio = nuevo;
		lista.fin = nuevo;
	} else {
		nuevo->sig = lista.inicio;
		lista.inicio->ant = nuevo;
		lista.inicio = nuevo;
	}
}

void AgregarFinal(tlista &lista, pnodo nuevo) {
	if (lista.inicio == NULL) {
		lista.inicio = nuevo;
		lista.fin = nuevo;
	} else {
		lista.fin->sig = nuevo;
		nuevo->ant = lista.fin;
		lista.fin = nuevo;
	}
}

void QuitarInicio(tlista &lista) {
	if (lista.inicio == NULL) {
		cout << "Lista vacía. No se puede eliminar." << endl;
		return;
	}
	
	pnodo eliminado = lista.inicio;
	
	if (lista.inicio == lista.fin) {
		lista.inicio = NULL;
		lista.fin = NULL;
	} else {
		lista.inicio = lista.inicio->sig;
		lista.inicio->ant = NULL;
	}
	
	cout << "Nodo eliminado del inicio: " << eliminado->dato << endl;
	delete eliminado;
}

void QuitarFinal(tlista &lista) {
	if (lista.fin == NULL) {
		cout << "Lista vacía. No se puede eliminar." << endl;
		return;
	}
	
	pnodo eliminado = lista.fin;
	
	if (lista.inicio == lista.fin) {
		lista.inicio = NULL;
		lista.fin = NULL;
	} else {
		lista.fin = lista.fin->ant;
		lista.fin->sig = NULL;
	}
	
	cout << "Nodo eliminado del final: " << eliminado->dato << endl;
	delete eliminado;
}
int main() {
	tlista lista;
	pnodo nuevo;
	
	IniciarLista(lista);
	
	CrearNodo(nuevo, 10);
	AgregarFinal(lista, nuevo);
	
	CrearNodo(nuevo, 20);
	AgregarFinal(lista, nuevo);
	
	CrearNodo(nuevo, 30);
	AgregarFinal(lista, nuevo);
	
	QuitarInicio(lista); 
	QuitarFinal(lista);  
	QuitarInicio(lista); 
	
	QuitarFinal(lista);  
	
	return 0;
}

