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

	T *DirObjeto(int);
	T *DirSiguienteObjeto(T *);

	void Desplegar();
	void DesplegarLinear();

	Nodo<T> *DesligarNodoCabeza();
	void LigarNodoFinal(Nodo<T> *);

	bool EstaVacia();

	int Tamano();
};
#include "Lista.cpp"