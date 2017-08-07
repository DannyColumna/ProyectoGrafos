
#include "stdafx.h"
#include "Nodo.h"

template <typename T>
Nodo<T>::Nodo()
{
}

template <typename T>
Nodo<T>::~Nodo()
{
}

template <typename T>
Nodo<T>::Nodo(T *_objeto) {
	this->SetObjeto(_objeto);
}

template <typename T>
void Nodo<T>::SetObjeto(T *_objeto) {
	this->objeto = _objeto;
}

template <typename T>
T *Nodo<T>::GetObjeto() {
	return this->objeto;
}

template <typename T>
void Nodo<T>::SetSiguiente(Nodo<T> *_siguiente) {
	this->siguiente = _siguiente;
}

template <typename T>
Nodo<T> *Nodo<T>::GetSiguiente() {
	return siguiente;
}

template <typename T>
void Nodo<T>::SetAnterior(Nodo<T> *_siguiente) {
	this->anterior = _siguiente;
}

template <typename T>
Nodo<T> *Nodo<T>::GetAnterior() {
	return anterior;
}