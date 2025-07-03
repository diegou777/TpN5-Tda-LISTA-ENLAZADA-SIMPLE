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

pnodo quitarInicio(pnodo &inicio) {
	pnodo extraido = NULL;
	if (inicio != NULL) {
		extraido = inicio;
		inicio = inicio->sig;
		if (inicio != NULL)
			inicio->ant = NULL;
		extraido->sig = NULL;
	}
	return extraido;
}

pnodo quitarFinal(pnodo &inicio) {
	if (inicio == NULL) return NULL;
	
	pnodo i = inicio;
	while (i->sig != NULL) i = i->sig;
	
	if (i->ant != NULL)
		i->ant->sig = NULL;
	else
		inicio = NULL;
	
	i->ant = NULL;
	return i;
}

pnodo quitarNodo(pnodo &inicio, int valor) {
	if (inicio == NULL) return NULL;
	
	pnodo i = inicio;
	
	if (i->dato == valor) {
		return quitarInicio(inicio);
	}
	
	while (i != NULL && i->dato != valor) {
		i = i->sig;
	}
	
	if (i != NULL) {
		if (i->ant != NULL)
			i->ant->sig = i->sig;
		if (i->sig != NULL)
			i->sig->ant = i->ant;
		
		i->sig = NULL;
		i->ant = NULL;
	}
	
	return i;
}

bool buscar(pnodo inicio, int valor) {
	pnodo i = inicio;
	while (i != NULL) {
		if (i->dato == valor) return true;
		i = i->sig;
	}
	return false;
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

int main() {
	pnodo lista, nuevo, eliminado;
	iniciarLista(lista);
	int opcion, valor;
	
	do {
		cout << "\n1. Agregar al inicio\n2. Agregar al final\n3. Agregar ordenado";
		cout << "\n4. Quitar del inicio\n5. Quitar del final\n6. Quitar nodo por valor";
		cout << "\n7. Buscar valor\n8. Mostrar lista\n9. Salir\nOpcion: ";
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
			eliminado = quitarInicio(lista);
			if (eliminado != NULL) {
				cout << "Eliminado: " << eliminado->dato << endl;
				delete eliminado;
			} else cout << "Lista vacia" << endl;
			break;
		case 5:
			eliminado = quitarFinal(lista);
			if (eliminado != NULL) {
				cout << "Eliminado: " << eliminado->dato << endl;
				delete eliminado;
			} else cout << "Lista vacia" << endl;
			break;
		case 6:
			cout << "Valor a eliminar: ";
			cin >> valor;
			eliminado = quitarNodo(lista, valor);
			if (eliminado != NULL) {
				cout << "Eliminado: " << eliminado->dato << endl;
				delete eliminado;
			} else cout << "No encontrado" << endl;
			break;
		case 7:
			cout << "Valor a buscar: ";
			cin >> valor;
			if (buscar(lista, valor)) {
				cout << "Encontrado" << endl;
			} else {
				cout << "No encontrado" << endl;
			}
			break;
			
		case 8:
			mostrarLista(lista);
			break;
		case 9:
			cout << "Saliendo..." << endl;
			break;
		default:
			cout << "Opcion invalida." << endl;
		}
	} while (opcion != 9);
	
	return 0;
}
