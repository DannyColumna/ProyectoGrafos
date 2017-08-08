#include "stdafx.h"
#include "RelacionMatriz.h"


RelacionMatriz::RelacionMatriz()
{
}


RelacionMatriz::RelacionMatriz(int indice, int valor)
{
	this->indice = indice;
	this->valor = valor;
}


RelacionMatriz::~RelacionMatriz()
{
}

void RelacionMatriz::setIndice(int indice)
{
	this->indice = indice;
}

int RelacionMatriz::getIndice()
{
	return this->indice;
}

void RelacionMatriz::setValor(int valor)
{
	this->valor = valor;
}

int RelacionMatriz::getValor()
{
	return this->valor;
}



bool RelacionMatriz::operator==(RelacionMatriz der) const
{
	return (this->indice == der.indice && this->valor == der.valor);
}
