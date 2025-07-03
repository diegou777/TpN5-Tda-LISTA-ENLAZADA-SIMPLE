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
		cout << i->dato << " ";
		i = i->sig;
	}
	cout << endl;
}
void MostrarMayorYMenor(tlista lista) {
	if (lista.inicio == NULL) {
		cout << "La lista está vacía." << endl;
		return;
	}
	
	int mayor = lista.inicio->dato;
	int menor = lista.inicio->dato;
	
	pnodo i = lista.inicio->sig;
	
	while (i != NULL) {
		if (i->dato > mayor) mayor = i->dato;
		if (i->dato < menor) menor = i->dato;
		i = i->sig;
	}
	
	cout << "Valor mayor en la lista: " << mayor << endl;
	cout << "Valor menor en la lista: " << menor << endl;
}

int main() {
	tlista lista;
	pnodo nuevo;
	
	IniciarLista(lista);
	
	int valores[] = {20, 5, 42, 13, 8};
	for (int i = 0; i < 5; i++) {
		CrearNodo(nuevo, valores[i]);
		AgregarFinal(lista, nuevo);
	}
	cout << "Lista cargada: " ;
	MostrarLista(lista);
	MostrarMayorYMenor(lista);
	
	return 0;
}
