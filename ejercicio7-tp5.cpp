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
int main() {
    // Crear la lista: 6 → 4 → 9 → 5 → 8 → NULL
    Nodo* n1 = new Nodo(6);
    Nodo* n2 = new Nodo(4);
    Nodo* n3 = new Nodo(9);
    Nodo* n4 = new Nodo(5);
    Nodo* n5 = new Nodo(8);

    // Enlazar
    n1->setSiguiente(n2);
    n2->setSiguiente(n3);
    n3->setSiguiente(n4);
    n4->setSiguiente(n5);

    // Probar enigma
    cout << "Salida de enigma (impresión en orden inverso):\n";
    enigma(n1);

    // Probar misterio
    int cantidad = misterio(n1);
    cout << "\nSalida de misterio (cantidad de nodos): " << cantidad << endl;

   //probar desconocido
    Nodo* ultimo = desconocido(n1);
    cout << "Salida de desconocido (último nodo): " << ultimo->getDato() << endl;

    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;

    return 0;
}
