#include "stdafx.h"
#include "Nodo.h"

template <class T>
Nodo<T>::Nodo()
{
}

template <class T>
Nodo<T>::~Nodo()
{
}

template <class T>
Nodo<T>::Nodo(T *_objeto) {
	this->SetObjeto(_objeto);
}

template <class T>
void Nodo<T>::SetObjeto(T *_objeto) {
	this->objeto = _objeto;
}

template <class T>
T *Nodo<T>::GetObjeto() {
	return this->objeto;
}

template <class T>
void Nodo<T>::SetSiguiente(Nodo<T> *_siguiente) {
	this->siguiente = _siguiente;
}

template <class T>
Nodo<T> *Nodo<T>::GetSiguiente() {
	return siguiente;
}

template <class T>
void Nodo<T>::SetAnterior(Nodo<T> *_siguiente) {
	this->anterior = _siguiente;
}

template <class T>
Nodo<T> *Nodo<T>::GetAnterior() {
	return anterior;
}