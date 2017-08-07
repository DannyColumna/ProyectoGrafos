#include "stdafx.h"
#include "Lista.h"

template <class T>
Lista<T>::Lista()
{
}

template <class T>
Lista<T>::~Lista()
{
}

template <class T>
void Lista<T>::SetCabeza(Nodo<T> *_cabeza) {
	this->cabeza = _cabeza;
}

template <class T>
Nodo<T> *Lista<T>::GetCabeza() {
	return this->cabeza;
}

template <class T>
void Lista<T>::InsertarInicio(T *objeto) {
	Nodo<T> *Temp = new Nodo<T>(objeto);
	Temp->SetSiguiente(this->GetCabeza());
	if (this->GetCabeza() != NULL) {
		this->GetCabeza()->SetAnterior(Temp);
	}
	this->SetCabeza(Temp);
}

template <class T>
void Lista<T>::InsertarFinal(T *objeto) {
	Nodo<T> *Temp = new Nodo<T>(objeto);
	if (!this->GetCabeza() == NULL) {
		Nodo<T> *Aux = this->GetCabeza();
		while (Aux->GetSiguiente() != NULL) {
			Aux = Aux->GetSiguiente();
		}
		Temp->SetAnterior(Aux);
		Aux->SetSiguiente(Temp);
	}
	else {
		this->SetCabeza(Temp);
	}
}

template <class T>
void Lista<T>::Desplegar() {
	if (!this->GetCabeza()) {
		cout << "La lista esta vacia" << endl;
	}
	else {
		Nodo<T> *Aux = this->GetCabeza();
		while (Aux != NULL) {
			cout << Aux->GetObjeto()->GetId() << endl;
			Aux = Aux->GetSiguiente();
		}
	}
	//system("PAUSE");
}

template <class T>
void Lista<T>::DesplegarLinear() {
	if (!this->GetCabeza()) {
		cout << "La lista esta vacia" << endl;
	}
	else {
		Nodo<T> *Aux = this->GetCabeza();
		while (Aux != NULL) {
			cout << Aux->GetObjeto() << " ";
			Aux = Aux->GetSiguiente();
		}
	}
	//system("PAUSE");
}

template <class T>
T * Lista<T>::DirObjeto(int _id) {
	Nodo<T> *Aux = this->GetCabeza();
	while (Aux != NULL) {
		if (Aux->GetObjeto()->GetId() == _id) {
			return Aux->GetObjeto();
		}
		Aux = Aux->GetSiguiente();
	}
	return NULL;
}

template <class T>
T *Lista<T>::DirSiguienteObjeto(T *_objeto) {
	if (_objeto == NULL) {
		return this->GetCabeza()->GetObjeto();
	}
	Nodo<T> *Aux = this->GetCabeza();
	while (Aux != NULL) {
		if (Aux->GetObjeto() == _objeto) {
			if (Aux->GetSiguiente() == NULL) {
				return this->GetCabeza()->GetObjeto();
			}
			return Aux->GetSiguiente()->GetObjeto();
		}
		Aux = Aux->GetSiguiente();
	}
	return NULL;
}

template <class T>
bool Lista<T>::EstaVacia() {
	return this->GetCabeza() == NULL;
}

template <class T>
Nodo<T> *Lista<T>::DesligarNodoCabeza() {
	if (this->GetCabeza() == NULL) {
		return NULL;
	}
	Nodo<T> *Aux = this->GetCabeza();
	this->SetCabeza(Aux->GetSiguiente());
	Aux->SetSiguiente(NULL);
	if (this->GetCabeza() != NULL) {
		this->GetCabeza()->SetAnterior(NULL);
	}
	return Aux;
}

template <class T>
void Lista<T>::LigarNodoFinal(Nodo<T> *Temp) {
	if (this->GetCabeza() == NULL) {
		this->SetCabeza(Temp);
	}
	else {
		Nodo<T> *Aux = this->GetCabeza();
		while (Aux->GetSiguiente() != NULL) {
			Aux = Aux->GetSiguiente();
		}
		Temp->SetAnterior(Aux);
		Aux->SetSiguiente(Temp);
	}
}

template <class T>
int Lista<T>::Tamano() {
	int contador = 0;
	if (!this->GetCabeza()) {
		cout << "Lista es vacia..." << endl;
	}
	else {
		Nodo<T> *aux = this->GetCabeza();
		while (aux != NULL) {
			contador++;
			aux = aux->GetSiguiente();
		}
	}
	return contador;
}