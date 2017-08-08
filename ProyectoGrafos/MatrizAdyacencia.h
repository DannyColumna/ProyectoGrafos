#pragma once
#include "Lista.h"
#include "RelacionMatriz.h"

class MatrizAdyacencia
{
private:
	int tamano;
	int **arr;
	const int MAX_TAMANO = 10000;
public:

	MatrizAdyacencia(int);
	~MatrizAdyacencia();

	int getTamano();
	void incrementar();
	void agregarArista(int, int, int);
	void desplegar();
	Lista<RelacionMatriz> * obtenerCamposEnFila(int);
	void eliminarCamposEnIndice(int);
	void editarArista(int, int, int);
};
