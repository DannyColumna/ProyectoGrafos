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
#define TIPO_HERMANO 4


#define SEXO_MASCULINO 'm'
#define SEXO_FEMENINO 'f'

class GrafoFamiliar
{
private:
	MatrizAdyacencia * matrizAdyacencia;
	Lista< PersonaGrafo > * personas;
	int numeroPersonas;
	void agregarRelaciones(PersonaGrafo*, Lista<RelacionPersona> *);
	void imprimirRelaciones(PersonaGrafo*, Lista<RelacionMatriz> *);
	PersonaGrafo * buscarPersonaPorIndiceEnMatriz(int);
	//Lista< RelacionMatriz > * obtenerRelacionesEnMatriz(int);
	Lista< RelacionMatriz > * buscarHermanos(int);

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
