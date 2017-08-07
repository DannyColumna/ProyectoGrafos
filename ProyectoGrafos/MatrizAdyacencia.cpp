#include "stdafx.h"
#include "MatrizAdyacencia.h"


MatrizAdyacencia::MatrizAdyacencia(int n)
{
	this->tamano = n;
	//visited = new bool[n];
	arr = new int*[MAX_TAMANO];
	for (int i = 0; i < MAX_TAMANO; i++) {
		arr[i] = new int[MAX_TAMANO];
		for (int j = 0; j < MAX_TAMANO; j++) {
			arr[i][j] = 0;
		}
	}
}


MatrizAdyacencia::~MatrizAdyacencia()
{
	for (int i = 0; i < this->tamano; i++) {
		delete arr[i];
	}

	delete arr;

}

void MatrizAdyacencia::incrementar() {
	this->tamano = (this->tamano + 1);
}


void MatrizAdyacencia::agregarArista(int origin, int destin, int t) {
	if (origin > this->tamano || destin > this->tamano || origin < 0 || destin < 0) {
		cout << "Invalid edge!\n";
	}
	else {
		//arr[origin - 1][destin - 1] = t;
		arr[origin][destin] = t;
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

Lista<RelacionMatriz> * MatrizAdyacencia::obtenerCamposEnFila(int indice)
{
	Lista<RelacionMatriz> * campos = new Lista<RelacionMatriz>();
	for (int j = 0; j < this->tamano; j++) {
		int valor= arr[indice][j];
		if (valor > 0 && indice != j) {
			campos->InsertarFinal(new RelacionMatriz(j, valor));
		}
	}

	return campos;
}
