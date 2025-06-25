#include<bits/stdc++.h>
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

void mostrar_lista(tlista lista) {
	pnodo i;
	if (!es_vacia(lista)) {
		cout << "Lista: ";
		for (i = lista.inicio; i != NULL; i = i->siguiente) {
			cout << i->dato << " ";
		}
		cout << endl;
	} else {
		cout << "Lista vacía" << endl;
	}
}

int obtener_cantidad(tlista lista) {
	return lista.cantidad;
}



int main() {
	tlista lista;
	iniciar_lista(lista);
	
	int datos[] = {7, 14, 21, 28, 35};
	for (int i = 0; i < 5; i++) {
		pnodo nuevo = new tnodo;
		nuevo->dato = datos[i];
		nuevo->siguiente = NULL;
		agregar_final(lista, nuevo);
	}
	
	mostrar_lista(lista);
	cout << "Cantidad de elementos: " << obtener_cantidad(lista) << endl;
	
	int indice;
	cout << "\nIngrese el índice que desea buscar: ";
	cin >> indice;
	
	pnodo encontrado = buscar_por_indice(lista, indice);
	
	if (encontrado != NULL) {
		cout << "Elemento en la posición " << indice << " es: " << encontrado->dato << endl;
	} else {
		cout << "indice fuera de rango." << endl;
	}
	
	return 0;
}
