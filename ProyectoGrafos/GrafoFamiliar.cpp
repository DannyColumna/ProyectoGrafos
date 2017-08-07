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
			this->matrizAdyacencia->agregarArista(p->getIndiceEnMatriz(), i, TIPO_NINGUNO);
			this->matrizAdyacencia->agregarArista(i, p->getIndiceEnMatriz(), TIPO_NINGUNO);
		}
	}
}

void GrafoFamiliar::agregarRelaciones(PersonaGrafo *persona, Lista<RelacionPersona>* relaciones)
{
	Nodo<RelacionPersona> * aux = relaciones->GetCabeza();
	while (aux != NULL) {
		RelacionPersona* rp = aux->GetObjeto();
		PersonaGrafo * rPersona = this->BuscarPersona(rp->getId());
		if (rp->getTipo() == TIPO_PATERNAL) {
			this->matrizAdyacencia->agregarArista(persona->getIndiceEnMatriz(), rPersona->getIndiceEnMatriz(), TIPO_PATERNAL);
			this->matrizAdyacencia->agregarArista(rPersona->getIndiceEnMatriz(), persona->getIndiceEnMatriz(), TIPO_DESCEDIENTE);

		}
		else if (rp->getTipo() == TIPO_DESCEDIENTE) {
			this->matrizAdyacencia->agregarArista(persona->getIndiceEnMatriz(), rPersona->getIndiceEnMatriz(), TIPO_DESCEDIENTE);
			this->matrizAdyacencia->agregarArista(rPersona->getIndiceEnMatriz(), persona->getIndiceEnMatriz(), TIPO_PATERNAL);

		}
		else if (rp->getTipo() == TIPO_CONYUGE) {
			this->matrizAdyacencia->agregarArista(persona->getIndiceEnMatriz(), rPersona->getIndiceEnMatriz(), TIPO_CONYUGE);
			this->matrizAdyacencia->agregarArista(rPersona->getIndiceEnMatriz(), persona->getIndiceEnMatriz(), TIPO_CONYUGE);

		}
		else if (rp->getTipo() == TIPO_NINGUNO) {
			this->matrizAdyacencia->agregarArista(persona->getIndiceEnMatriz(), rPersona->getIndiceEnMatriz(), TIPO_NINGUNO);
			this->matrizAdyacencia->agregarArista(rPersona->getIndiceEnMatriz(), persona->getIndiceEnMatriz(), TIPO_NINGUNO);

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

