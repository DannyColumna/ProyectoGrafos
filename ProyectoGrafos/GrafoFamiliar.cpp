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

void GrafoFamiliar::DesplegarPorPersona()
{
	Nodo<PersonaGrafo> * auxP = this->personas->GetCabeza();

	while (auxP != NULL) {
		PersonaGrafo * persona = auxP->GetObjeto();
		if (persona == NULL) {
			auxP = auxP->GetSiguiente();
			continue;
		}
		Lista<RelacionMatriz> * relaciones = matrizAdyacencia->obtenerCamposEnFila(persona->getIndiceEnMatriz());//obtenerRelacionesEnMatriz(persona->getIndiceEnMatriz());
			
		
		if (relaciones != NULL && !relaciones->EstaVacia()) {
			imprimirRelaciones(persona, relaciones);
			Lista<RelacionMatriz> * hermanos = buscarHermanos(persona->getIndiceEnMatriz());
			if (hermanos != NULL && !hermanos->EstaVacia()) {
				imprimirRelaciones(persona, hermanos);
			}
		}
		else {
			cout << persona << " no tiene relaciones familiares" << endl;
		}

		auxP = auxP->GetSiguiente();
	}
}

void GrafoFamiliar::imprimirRelaciones(PersonaGrafo * p, Lista<RelacionMatriz>* relaciones)
{
	Nodo<RelacionMatriz> * auxP = relaciones->GetCabeza();


	while (auxP != NULL) {
		RelacionMatriz * r = auxP->GetObjeto();
		cout << p->getNombre();
		if (r->getValor() == TIPO_PATERNAL) {
			cout << " es padre de ";
		}
		else if (r->getValor() == TIPO_DESCEDIENTE) {
			cout << " es hijo de ";
		}
		else if (r->getValor() == TIPO_CONYUGE) {
			cout << " es conyuge de ";
		}
		else if (r->getValor() == TIPO_HERMANO) {
			cout << " es hermano de ";
		}
		else {
			cout << "[ERROR]NO DEBERIA SUCEDER!!";
		}
		PersonaGrafo * pRelacionada =  buscarPersonaPorIndiceEnMatriz(r->getIndice());
		if (pRelacionada == NULL) {
			cout << " [Error] ";
		}
		else {
			cout << pRelacionada->getNombre() << endl;
		}
		auxP = auxP->GetSiguiente();
	}
}

PersonaGrafo * GrafoFamiliar::buscarPersonaPorIndiceEnMatriz(int indice)
{
	PersonaGrafo *resultado = NULL;
	Nodo<PersonaGrafo> *aux = this->personas->GetCabeza();
	while (aux != NULL) {
		if (aux->GetObjeto()->getIndiceEnMatriz()== indice) {
			resultado = aux->GetObjeto();
			break;
		}
		aux = aux->GetSiguiente();
	}
	return resultado;
}

//Lista<RelacionMatriz>* GrafoFamiliar::obtenerRelacionesEnMatriz(int indice)
//{
	//Lista<RelacionMatriz> * resultado = matrizAdyacencia->obtenerCamposEnFila(indice);

	//Lista<RelacionMatriz> * resultado2 = buscarHermanos( indice);
	//return resultado;
//}

Lista<RelacionMatriz>* GrafoFamiliar::buscarHermanos(int indice)
{
	int indicePaternal1 = -1;
	int indicePaternal2 = -1;

	Lista<RelacionMatriz> * hermanos = new Lista<RelacionMatriz>();
	// obtener padres
	Lista<RelacionMatriz> * resultado = matrizAdyacencia->obtenerCamposEnFila(indice);
	if (resultado != NULL && !resultado->EstaVacia()) {

		Nodo<RelacionMatriz> * auxP = resultado->GetCabeza();


		while (auxP != NULL) {
			RelacionMatriz * r = auxP->GetObjeto();
			
			if (r->getValor() == TIPO_DESCEDIENTE) {
				if (indicePaternal1 == -1) {
					indicePaternal1 = r->getIndice();
				}
				else {
					indicePaternal2 = r->getIndice();
				}
			}

			
			auxP = auxP->GetSiguiente();
		}

	}


	// para cada padre, extraer hijos
	if (indicePaternal1 != -1) {
		Lista<RelacionMatriz> * relacionesPaternal1 = matrizAdyacencia->obtenerCamposEnFila(indicePaternal1);
		if (relacionesPaternal1 != NULL && !relacionesPaternal1->EstaVacia()) {

			Nodo<RelacionMatriz> * auxP = relacionesPaternal1->GetCabeza();


			while (auxP != NULL) {
				RelacionMatriz * r = auxP->GetObjeto();

				if (r->getValor() == TIPO_PATERNAL && indice != r->getIndice()) {
					// agregar hermano
					hermanos->InsertarUnico(new RelacionMatriz(r->getIndice(), TIPO_HERMANO));
				}
				auxP = auxP->GetSiguiente();
			}
		}
	}

	if (indicePaternal2 != -1) {
		Lista<RelacionMatriz> * relacionesPaternal2 = matrizAdyacencia->obtenerCamposEnFila(indicePaternal2);
		if (relacionesPaternal2 != NULL && !relacionesPaternal2->EstaVacia()) {

			Nodo<RelacionMatriz> * auxP = relacionesPaternal2->GetCabeza();


			while (auxP != NULL) {
				RelacionMatriz * r = auxP->GetObjeto();

				if (r->getValor() == TIPO_PATERNAL&& indice != r->getIndice()) {
					// agregar hermano
					hermanos->InsertarUnico(new RelacionMatriz(r->getIndice(), TIPO_HERMANO));
				}
				auxP = auxP->GetSiguiente();
			}
		}
	}
	return hermanos;
}

void GrafoFamiliar::DesplegarTodo()
{

	cout << "Personas: -- > " << endl;
	this->personas->DesplegarLinear();
	cout << "Matrix Adyacente: -->" << endl;
	this->matrizAdyacencia->desplegar();
}

