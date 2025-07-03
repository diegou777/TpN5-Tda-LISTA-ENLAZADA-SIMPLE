#include <iostream>
using namespace std;

typedef struct tnodo* pnodo;
typedef struct tnodo {
	int dato;
	pnodo sig;
	pnodo ant;
} tnodo;

void iniciarLista(pnodo &inicio) {
	inicio = NULL;
}

void crearNodo(pnodo &nuevo) {
	int valor;
	cout << "Ingrese valor: ";
	cin >> valor;
	nuevo = new tnodo;
	nuevo->dato = valor;
	nuevo->sig = NULL;
	nuevo->ant = NULL;
}
void agregarInicio(pnodo &inicio, pnodo nuevo) {
	if (inicio == NULL)
		inicio = nuevo;
	else {
		nuevo->sig = inicio;
		inicio->ant = nuevo;
		inicio = nuevo;
	}
}

void agregarFinal(pnodo &inicio, pnodo nuevo) {
	if (inicio == NULL) {
		inicio = nuevo;
	} else {
		pnodo i = inicio;
		while (i->sig != NULL) i = i->sig;
		i->sig = nuevo;
		nuevo->ant = i;
	}
}

void agregarOrdenado(pnodo &inicio, pnodo nuevo) {
	if (inicio == NULL || nuevo->dato < inicio->dato) {
		agregarInicio(inicio, nuevo);
	} else {
		pnodo i = inicio;
		while (i->sig != NULL && i->sig->dato < nuevo->dato) i = i->sig;
		nuevo->sig = i->sig;
		if (i->sig != NULL) i->sig->ant = nuevo;
		nuevo->ant = i;
		i->sig = nuevo;
	}
}

void mostrarLista(pnodo inicio) {
	if (inicio == NULL) {
		cout << "Lista vacia" << endl;
		return;
	}
	for (pnodo i = inicio; i != NULL; i = i->sig)
		cout << i->dato << " <-> ";
	cout << "NULL" << endl;
}

bool buscar(pnodo inicio, int valor) {
	pnodo i = inicio;
	while (i != NULL) {
		if (i->dato == valor) return true;
		i = i->sig;
	}
	return false;
}

int main() {
	pnodo lista, nuevo;
	iniciarLista(lista);
	int opcion, valor;
	
	do {
		cout << "\n1. Agregar al inicio\n2. Agregar al final\n3. Agregar ordenado\n4. Mostrar lista\n5. Buscar valor\n6. Salir\nOpcion: ";
		cin >> opcion;
		
		switch(opcion) {
		case 1:
			crearNodo(nuevo);
			agregarInicio(lista, nuevo);
			break;
		case 2:
			crearNodo(nuevo);
			agregarFinal(lista, nuevo);
			break;
		case 3:
			crearNodo(nuevo);
			agregarOrdenado(lista, nuevo);
			break;
		case 4:
			mostrarLista(lista);
			break;
		case 5:
			cout << "Ingrese valor a buscar: ";
			cin >> valor;
			if (buscar(lista, valor))
				cout << "Valor encontrado.\n";
			else
				cout << "Valor no encontrado.\n";
			break;
		case 6:
			cout << "Saliendo..." << endl;
			break;
		default:
			cout << "Opcion invalida.\n";
		}
		
	} while (opcion != 6);
	
}
