#pragma once
#include "Lista.h"
#include "RelacionMatriz.h"
template class Lista<RelacionMatriz>;
class MatrizAdyacencia
{
private:
	int tamano;
	int **arr;
	//bool *visited;
	const int MAX_TAMANO = 10000;
public:

	MatrizAdyacencia(int);
	~MatrizAdyacencia();

	int getTamano();
	void incrementar();
	void agregarArista(int, int, int);
	void desplegar();
	Lista<RelacionMatriz> * obtenerCamposEnFila(int);
};
