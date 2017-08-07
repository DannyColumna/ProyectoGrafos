#pragma once

template <typename T>
class Nodo
{
private:
	T *objeto;

	Nodo<T> *siguiente;
	Nodo<T> *anterior;
public:
	Nodo();
	~Nodo();

	Nodo(T *);

	void SetObjeto(T *);
	T *GetObjeto();

	void SetSiguiente(Nodo<T> *);
	Nodo<T> *GetSiguiente();

	void SetAnterior(Nodo<T> *);
	Nodo<T> *GetAnterior();

	//friend ostream& operator<<(ostream& os, const PersonaGrafo& pg);
	//friend ostream& operator<<(ostream& os, PersonaGrafo* pg);
};
#include "Nodo.cpp"