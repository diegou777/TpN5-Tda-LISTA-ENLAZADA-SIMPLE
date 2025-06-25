#include<bits/stdc++.h>
using namespace std;
//6: Lista genérica con templates
template <typename T>
struct Nodo {
	T dato;
	Nodo<T>* siguiente;
};

template <typename T>
class Lista {
private:
	Nodo<T>* inicio;
	
public:
	Lista() {
		inicio = nullptr;
	}
	
	void agregarFinal(T valor) {
		Nodo<T>* nuevo = new Nodo<T>;
		nuevo->dato = valor;
		nuevo->siguiente = nullptr;
		
		if (inicio == nullptr) {
			inicio = nuevo;
		} else {
			Nodo<T>* aux = inicio;
			while (aux->siguiente != nullptr) {
				aux = aux->siguiente;
			}
			aux->siguiente = nuevo;
		}
	}
	
	void mostrar() {
		Nodo<T>* aux = inicio;
		while (aux != nullptr) {
			cout << aux->dato << " -> ";
			aux = aux->siguiente;
		}
		cout << "NULL" << endl;
	}
	
	Nodo<T>* getInicio() {
		return inicio;
	}
};
//6a. Contar números primos en una lista de enteros
bool esPrimo(int n) {
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}
int contarPrimos(Lista<int>& lista) {
	int contador = 0;
	Nodo<int>* aux = lista.getInicio();
	
	while (aux != nullptr) {
		if (esPrimo(aux->dato)) {
			contador++;
		}
		aux = aux->siguiente;
	}
	
	return contador;
}
//6b. Contar mayúsculas y minúsculas en lista de caracteres
void contarMayusMinus(Lista<char>& lista, int &mayus, int &minus) {
	mayus = 0;
	minus = 0;
	Nodo<char>* aux = lista.getInicio();
	
	while (aux != nullptr) {
		if (isupper(aux->dato))
			mayus++;
		else if (islower(aux->dato))
			minus++;
		aux = aux->siguiente;
	}
}
