#include <iostream>
using namespace std;

class Nodo {
private:
	int dato;
	Nodo* siguiente;
	
public:
	Nodo(int valor) {
		dato = valor;
		siguiente = nullptr;
	}
	
	int getDato() { return dato; }
	Nodo* getSiguiente() { return siguiente; }
	void setSiguiente(Nodo* sig) { siguiente = sig; }
};
//fragemnto 1
//Recorre la lista hasta el final recursivamente.
//Imprime los datos al volver de la recursión.
//Es decir, imprime la lista en orden inverso.
void enigma(Nodo* nodo) {
	if (nodo != nullptr)
		if (nodo->getSiguiente() == nullptr)
			cout << nodo->getDato() << endl;
		else {
		enigma(nodo->getSiguiente());
		cout << nodo->getDato() << endl;
		}
}
//fragmento 2
//Cuenta la cantidad de nodos en la lista usando recursión.
//Va al final (nullptr) y suma +1 por cada nodo al volver.
int misterio(Nodo* nodo) {
	if (nodo == nullptr)
		return 0;
	else
		return misterio(nodo->getSiguiente()) + 1;
}

//fragmento 3
//Llega al último nodo de la lista recursivamente.	
//Devuelve un puntero al nodo cuyo siguiente == nullptr.
Nodo* desconocido(Nodo* nodo) {
	if (nodo == nullptr || nodo->getSiguiente() == nullptr)
		return nodo;
	else
		return desconocido(nodo->getSiguiente());
}
