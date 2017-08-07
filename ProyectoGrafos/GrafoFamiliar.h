#pragma once
#include "stdafx.h"
#include "Nodo.h"

#include "Lista.h"
//#include "Lista.cpp"
#include "MatrizAdyacencia.h"
#include "PersonaGrafo.h"
#include "Persona.h"

#include "RelacionPersona.h"

#define TIPO_NINGUNO 0
#define TIPO_DESCEDIENTE 1
#define TIPO_PATERNAL 2
#define TIPO_CONYUGE 3
template class Lista<RelacionMatriz>;
template class Lista<RelacionPersona>;
template class Lista<PersonaGrafo>;
class GrafoFamiliar
{
private:
	MatrizAdyacencia * matrizAdyacencia;
	Lista< PersonaGrafo > * personas;
	int numeroPersonas;
	void agregarRelaciones(PersonaGrafo*, Lista<RelacionPersona> *);
	void imprimirRelaciones(PersonaGrafo*, Lista<RelacionMatriz> *);
	PersonaGrafo * buscarPersonaPorIndiceEnMatriz(int);
public:
	GrafoFamiliar();
	~GrafoFamiliar();

	void AgregarPersona(Persona*, Lista<RelacionPersona> *);
	void EliminarPersona(int);
	void EditarPersona(Persona*);
	PersonaGrafo *BuscarPersona(char*);
	void DesplegarPorPersona();
	void DesplegarTodo();
};
