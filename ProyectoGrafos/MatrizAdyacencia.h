#pragma once

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
};
