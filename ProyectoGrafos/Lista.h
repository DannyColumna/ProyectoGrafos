#pragma once
#include "Nodo.h"
template <typename T>
class Lista
{
private:
	Nodo<T> *cabeza;

public:
	Lista();
	~Lista();

	void SetCabeza(Nodo<T> *);
	Nodo<T> *GetCabeza();

	void InsertarInicio(T *);
	void InsertarFinal(T *);
	void InsertarUnico(T *);

	T *DirObjeto(int);
	T *DirSiguienteObjeto(T *);

	void Desplegar();
	void DesplegarLinear();

	Nodo<T> *DesligarNodoCabeza();
	void LigarNodoFinal(Nodo<T> *);

	bool EstaVacia();
	bool EliminarPorDato(T *);
	int Tamano();
};


//
template <typename T>
Lista<T>::Lista()
{
}

template <typename T>
Lista<T>::~Lista()
{
}

template <typename T>
void Lista<T>::SetCabeza(Nodo<T> *_cabeza) {
	this->cabeza = _cabeza;
}

template <typename T>
Nodo<T> *Lista<T>::GetCabeza() {
	return this->cabeza;
}

template <typename T>
void Lista<T>::InsertarInicio(T *objeto) {
	Nodo<T> *Temp = new Nodo<T>(objeto);
	Temp->SetSiguiente(this->GetCabeza());
	if (this->GetCabeza() != NULL) {
		this->GetCabeza()->SetAnterior(Temp);
	}
	this->SetCabeza(Temp);
}

template <typename T>
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

template<typename T>
void Lista<T>::InsertarUnico(T *objeto)
{
	// Insertar unicos
	Nodo<T> *Temp = new Nodo<T>(objeto);
	if (!this->GetCabeza() == NULL) {
		Nodo<T> *Aux = this->GetCabeza();
		bool duplicado = false;
		while (Aux->GetSiguiente() != NULL) {
			T ojetoAux = *Aux->GetObjeto();
			T objetoCopia = *objeto;
			if (ojetoAux == objetoCopia) {
				duplicado = true;
				break;
			}
			Aux = Aux->GetSiguiente();
		}
		if (!duplicado) {
			Temp->SetAnterior(Aux);
			Aux->SetSiguiente(Temp);
		}
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
			T * t = (Aux->GetObjeto());
			cout << t << " ";
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

template<typename T>
bool Lista<T>::EliminarPorDato(T * dato)
{
	bool eliminado = false;
	
	if (this->GetCabeza() != NULL) {
		Nodo<T> *Aux = this->GetCabeza();
		Nodo<T> *Borrar = NULL;
		if (Aux->GetObjeto() == dato) {
			Borrar = Aux;
			this->SetCabeza(Borrar->GetSiguiente());
		}
		else {
			while (Aux->GetSiguiente() != NULL && Aux->GetSiguiente()->GetObjeto() != dato) {
				Aux = Aux->GetSiguiente();
			}
			if (Aux->GetSiguiente() != NULL) {
				Borrar = Aux->GetSiguiente();
			}
			if (Borrar != NULL) {
				Aux->SetSiguiente(Borrar->GetSiguiente());
			}
		}
		if (Borrar != NULL) {
			Borrar->SetSiguiente(NULL);
			delete(Borrar);
			//this->tamano--;
			eliminado = true;
		}
	}
	return eliminado;
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