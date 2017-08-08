#include "stdafx.h"
#include "MatrizAdyacencia.h"


MatrizAdyacencia::MatrizAdyacencia(int numero) {
	this->tamano = numero;
	arr = new int*[MAX_TAMANO];
	for (int i = 0; i < MAX_TAMANO; i++) {
		arr[i] = new int[MAX_TAMANO];
		for (int j = 0; j < MAX_TAMANO; j++) {
			arr[i][j] = 0;
		}
	}
}

MatrizAdyacencia::~MatrizAdyacencia() {
	for (int i = 0; i < this->tamano; i++) {
		delete arr[i];
	}
	delete arr;
}

void MatrizAdyacencia::incrementar() {
	this->tamano = (this->tamano + 1);
}

void MatrizAdyacencia::agregarArista(int origen, int destino, int t) {
	if (origen > this->tamano || destino > this->tamano || origen < 0 || destino < 0) {
		cout << "Lado es invalido...\n";
	}
	else {
		arr[origen][destino] = t;
	}
}

int MatrizAdyacencia::getTamano() {
	return this->tamano;
}

void MatrizAdyacencia::desplegar() {
	int i, j;
	for (i = 0; i < this->tamano; i++) {
		for (j = 0; j < this->tamano; j++) {
			cout << arr[i][j] << "  ";
		}
		cout << endl;
	}
}

Lista<RelacionMatriz> * MatrizAdyacencia::obtenerCamposEnFila(int indice) {
	Lista<RelacionMatriz> * campos = new Lista<RelacionMatriz>();
	for (int j = 0; j < this->tamano; j++) {
		int valor= arr[indice][j];
		if (valor > 0 && indice != j) {
			campos->InsertarFinal(new RelacionMatriz(j, valor));
		}
	}
	return campos;
}

void MatrizAdyacencia::eliminarCamposEnIndice(int indice)
{
	for (int j = 0; j < this->tamano; j++) {
		arr[indice][j] = 0;
	}

	for (int i = 0; i < this->tamano; i++) {
		arr[i][indice] = 0;
	}
}

void MatrizAdyacencia::editarArista(int origen, int destino, int t)
{
	arr[origen][destino] = t;
}
