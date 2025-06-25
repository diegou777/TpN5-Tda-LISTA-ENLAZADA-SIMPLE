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
int main() {
    // 6a - Lista de enteros
    Lista<int> listaEnteros;
    listaEnteros.agregarFinal(2);
    listaEnteros.agregarFinal(4);
    listaEnteros.agregarFinal(5);
    listaEnteros.agregarFinal(8);
    listaEnteros.agregarFinal(11);

    cout << "Lista de enteros:\n";
    listaEnteros.mostrar();

    int primos = contarPrimos(listaEnteros);
    cout << "Cantidad de números primos en la lista: " << primos << endl << endl;

    // 6b - Lista de caracteres
    Lista<char> listaChars;
    listaChars.agregarFinal('A');
    listaChars.agregarFinal('b');
    listaChars.agregarFinal('C');
    listaChars.agregarFinal('d');
    listaChars.agregarFinal('e');

    cout << "Lista de caracteres:\n";
    listaChars.mostrar();

    int mayus = 0, minus = 0;
    contarMayusMinus(listaChars, mayus, minus);
    cout << "Mayúsculas: " << mayus << endl;
    cout << "Minúsculas: " << minus << endl;

    return 0;
}
