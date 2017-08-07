#include "stdafx.h"
#include "GrafoFamiliar.h"



GrafoFamiliar::GrafoFamiliar()
{

	this->personas = new Lista<PersonaGrafo>();
	this->matrizAdyacencia = new MatrizAdyacencia(0);
}


GrafoFamiliar::~GrafoFamiliar()
{
	delete personas;
	delete matrizAdyacencia;
}

void GrafoFamiliar::AgregarPersona(Persona *persona, Lista<RelacionPersona> * relaciones)
{
	PersonaGrafo * p = new PersonaGrafo(
		this->matrizAdyacencia->getTamano(),
		persona->getId(),
		persona->getNombre(),
		persona->getFechaDeNacimiento());
	this->personas->InsertarFinal(p);
	this->matrizAdyacencia->incrementar();
	if (relaciones != NULL && !relaciones->EstaVacia()) {
		// buscar por ID y obtener indice cada relacionPersona
		this->agregarRelaciones(p, relaciones);
	}
	else {
		int tamanoMatrix = this->matrizAdyacencia->getTamano();
		for (int i = 0; i < tamanoMatrix; i++) {
			this->matrizAdyacencia->agregarArista(p->getIndiceEnMatriz(), i, MatrizAdyacencia::NINGUNO);
			this->matrizAdyacencia->agregarArista(i, p->getIndiceEnMatriz(), MatrizAdyacencia::NINGUNO);
		}
	}
}

void GrafoFamiliar::agregarRelaciones(PersonaGrafo *persona, Lista<RelacionPersona>* relaciones)
{
	Nodo<RelacionPersona> * aux = relaciones->GetCabeza();
	while (aux != NULL) {
		RelacionPersona* rp = aux->GetObjeto();
		PersonaGrafo * rPersona = this->BuscarPersona(rp->getId());
		if (rp->getTipo() == RelacionPersona::PATERNAL) {
			this->matrizAdyacencia->agregarArista(persona->getIndiceEnMatriz(), rPersona->getIndiceEnMatriz(), MatrizAdyacencia::PATERNAL);
			this->matrizAdyacencia->agregarArista(rPersona->getIndiceEnMatriz(), persona->getIndiceEnMatriz(), MatrizAdyacencia::DESCEDIENTE);

		}
		else if (rp->getTipo() == RelacionPersona::DESCEDIENTE) {
			this->matrizAdyacencia->agregarArista(persona->getIndiceEnMatriz(), rPersona->getIndiceEnMatriz(), MatrizAdyacencia::DESCEDIENTE);
			this->matrizAdyacencia->agregarArista(rPersona->getIndiceEnMatriz(), persona->getIndiceEnMatriz(), MatrizAdyacencia::PATERNAL);

		}
		else if (rp->getTipo() == RelacionPersona::CONYUGE) {
			this->matrizAdyacencia->agregarArista(persona->getIndiceEnMatriz(), rPersona->getIndiceEnMatriz(), MatrizAdyacencia::CONYUGE);
			this->matrizAdyacencia->agregarArista(rPersona->getIndiceEnMatriz(), persona->getIndiceEnMatriz(), MatrizAdyacencia::CONYUGE);

		}
		else if (rp->getTipo() == RelacionPersona::NINGUNO) {
			this->matrizAdyacencia->agregarArista(persona->getIndiceEnMatriz(), rPersona->getIndiceEnMatriz(), MatrizAdyacencia::NINGUNO);
			this->matrizAdyacencia->agregarArista(rPersona->getIndiceEnMatriz(), persona->getIndiceEnMatriz(), MatrizAdyacencia::NINGUNO);

		}


		aux = aux->GetSiguiente();
	}
}


void GrafoFamiliar::EliminarPersona(int ID)
{
}

void GrafoFamiliar::EditarPersona(Persona* persona)
{
}

PersonaGrafo *GrafoFamiliar::BuscarPersona(char * ID)
{
	PersonaGrafo* p = NULL;

	Nodo<PersonaGrafo> * aux = personas->GetCabeza();
	while (aux != NULL) {
		if (strcmp(aux->GetObjeto()->getId(), ID) == 0) {
			p = aux->GetObjeto();
		}
		aux = aux->GetSiguiente();
	}

	return p;
}

void GrafoFamiliar::DesplegarTodo()
{

	cout << "Personas: -- > " << endl;
	this->personas->DesplegarLinear();
	cout << "Matrix Adyacente: -->" << endl;
	this->matrizAdyacencia->desplegar();
}

