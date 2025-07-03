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

void MostrarLista(tlista lista) {
	pnodo i = lista.inicio;
	while (i != NULL) {
		cout << i->dato;
		i = i->sig;
	}
	cout << " (binario)" << endl;
}

void DecimalABinario(int numero, tlista &lista) {
	IniciarLista(lista);  
	
	if (numero == 0) {
		pnodo nodo;
		CrearNodo(nodo, 0);
		AgregarInicio(lista, nodo);
		return;
	}
	
	while (numero > 0) {
		int bit = numero % 2;
		pnodo nodo;
		CrearNodo(nodo, bit);
		AgregarInicio(lista, nodo);
		numero /= 2;
	}
}
int main() {
	tlista listaBinaria;
	int numero;
	
	cout << "Ingrese un número decimal: ";
	cin >> numero;
	
	DecimalABinario(numero, listaBinaria);
	
	cout << "Número en binario: ";
	MostrarLista(listaBinaria);
	
	return 0;
}
