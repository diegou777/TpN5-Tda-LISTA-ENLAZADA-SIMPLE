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

void MostrarLista(tlista lista) {
	pnodo i = lista.inicio;
	while (i != NULL) {
		cout << i->dato << " <-> ";
		i = i->sig;
	}
	cout << "NULL" << endl;
}

void EliminarMultiplosDe3(tlista &lista) {
	pnodo actual = lista.inicio;
	pnodo borrar;
	
	while (actual != NULL) {
		if (actual->dato % 3 == 0) {
			borrar = actual;
			
			if (actual == lista.inicio && actual == lista.fin) {
				lista.inicio = NULL;
				lista.fin = NULL;
			} else if (actual == lista.inicio) {
				lista.inicio = actual->sig;
				lista.inicio->ant = NULL;
			} else if (actual == lista.fin) {
				lista.fin = actual->ant;
				lista.fin->sig = NULL;
			} else {
				actual->ant->sig = actual->sig;
				actual->sig->ant = actual->ant;
			}
			
			actual = actual->sig;
			delete borrar;
		} else {
			actual = actual->sig;
		}
	}
}


int main() {
	tlista lista;
	pnodo nuevo;
	
	IniciarLista(lista);
	
	int valores[] = {9, 2, 3, 7, 12, 5};
	for (int i = 0; i < 6; i++) {
		CrearNodo(nuevo, valores[i]);
		AgregarFinal(lista, nuevo);
	}
	
	cout << "Lista original:\n";
	MostrarLista(lista);
	
	EliminarMultiplosDe3(lista);
	
	cout << "Lista después de eliminar múltiplos de 3:\n";
	MostrarLista(lista);
	
	return 0;
}
