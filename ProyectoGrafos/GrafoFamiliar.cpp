#include "stdafx.h"
#include "GrafoFamiliar.h"


GrafoFamiliar::GrafoFamiliar() {

	this->personas = new Lista<PersonaGrafo>();
	this->matrizAdyacencia = new MatrizAdyacencia(0);
}


GrafoFamiliar::~GrafoFamiliar() {
	delete personas;
	delete matrizAdyacencia;
}

void GrafoFamiliar::AgregarPersona(Persona *persona, Lista<RelacionPersona> * relaciones) {
	PersonaGrafo * p = new PersonaGrafo(
		this->matrizAdyacencia->getTamano(),
		persona->getId(),
		persona->getNombre(),
		persona->getFechaDeNacimiento(),
		persona->getSexo());
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

void GrafoFamiliar::agregarRelaciones(PersonaGrafo *persona, Lista<RelacionPersona>* relaciones) {
	Nodo<RelacionPersona> * aux = relaciones->GetCabeza();
	while (aux != NULL) {
		RelacionPersona* rp = aux->GetObjeto();
		PersonaGrafo * rPersona = this->buscarPersona(rp->getId());
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


void GrafoFamiliar::EliminarPersona(char* ID)
{
	PersonaGrafo * personaAEliminar = this->buscarPersona(ID);
	matrizAdyacencia->eliminarCamposEnIndice(personaAEliminar->getIndiceEnMatriz());
	personas->EliminarPorDato(personaAEliminar);
}

void GrafoFamiliar::EditarRelacionPersona(char *id, RelacionPersona *relacionPersona)
{
	PersonaGrafo *pOrigen = this->buscarPersona(id);
	PersonaGrafo *pDestino = this->buscarPersona(relacionPersona->getId());
	int indiceOrigen = pOrigen->getIndiceEnMatriz();
	int indiceDestino = pDestino->getIndiceEnMatriz();
	int tipo = relacionPersona->getTipo();
	if (tipo == TIPO_PATERNAL) {
		this->matrizAdyacencia->editarArista(indiceOrigen, indiceDestino, TIPO_PATERNAL);
		this->matrizAdyacencia->editarArista(indiceDestino,indiceOrigen,  TIPO_DESCEDIENTE);

	}
	else if (tipo == TIPO_DESCEDIENTE) {
		this->matrizAdyacencia->editarArista(indiceOrigen, indiceDestino, TIPO_DESCEDIENTE);
		this->matrizAdyacencia->editarArista(indiceDestino, indiceOrigen, TIPO_PATERNAL);

	}
	else if (tipo == TIPO_CONYUGE) {
		this->matrizAdyacencia->editarArista(indiceOrigen, indiceDestino, TIPO_CONYUGE);
		this->matrizAdyacencia->editarArista(indiceDestino, indiceOrigen, TIPO_CONYUGE);

	}
	else if (tipo == TIPO_NINGUNO) {
		this->matrizAdyacencia->editarArista(indiceOrigen, indiceDestino, TIPO_NINGUNO);
		this->matrizAdyacencia->editarArista(indiceDestino, indiceOrigen, TIPO_NINGUNO);

	}
}

void GrafoFamiliar::EditarPersona(char*id, Persona* persona)
{
	PersonaGrafo *p = this->buscarPersona(id);
	p->setId(persona->getId());
	p->setNombre(persona->getNombre());
	p->setFechaNacimiento(persona->getFechaDeNacimiento());
	p->setSexo(persona->getSexo());
}

void GrafoFamiliar::BuscarPersona(char * id)
{
	PersonaGrafo *p = this->buscarPersona(id);
	imprimirPersona(p);
}

PersonaGrafo *GrafoFamiliar::buscarPersona(char * ID) {
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

void GrafoFamiliar::imprimirPersona(PersonaGrafo * persona)
{
	if (persona != NULL && persona->getIndiceEnMatriz()>=0) {
		Lista<RelacionMatriz> * relaciones = matrizAdyacencia->obtenerCamposEnFila(persona->getIndiceEnMatriz());//obtenerRelacionesEnMatriz(persona->getIndiceEnMatriz());

		if (relaciones != NULL && !relaciones->EstaVacia()) {
			imprimirRelaciones(persona, relaciones);



			Lista<RelacionMatriz> * hermanos = buscarHermanos(persona->getIndiceEnMatriz());
			if (hermanos != NULL && !hermanos->EstaVacia()) {
				imprimirRelaciones(persona, hermanos);
			}

			Lista<RelacionMatriz> * abuelos = buscarAbuelos(persona->getIndiceEnMatriz());
			if (abuelos != NULL && !abuelos->EstaVacia()) {
				imprimirRelaciones(persona, abuelos);
			}
		}
		else {
			cout << persona << " no tiene relaciones familiares" << endl;
		}
	}
}

void GrafoFamiliar::DesplegarPorPersona() {
	Nodo<PersonaGrafo> * auxP = this->personas->GetCabeza();
	while (auxP != NULL) {
		PersonaGrafo * persona = auxP->GetObjeto();
		if (persona == NULL) {
			auxP = auxP->GetSiguiente();
			continue;
		}
		
		imprimirPersona(persona);
		auxP = auxP->GetSiguiente();
	}
}

void GrafoFamiliar::imprimirRelaciones(PersonaGrafo * p, Lista<RelacionMatriz>* relaciones) {
	Nodo<RelacionMatriz> * auxP = relaciones->GetCabeza();

	while (auxP != NULL) {
		RelacionMatriz * r = auxP->GetObjeto();

		PersonaGrafo * pRelacionada = buscarPersonaPorIndiceEnMatriz(r->getIndice());
		if (pRelacionada == NULL) {
			cout << " [Error] ";
			continue;
		}
		char sexo = p->getSexo();
		cout << p->getNombre();
		if (r->getValor() == TIPO_PATERNAL) {
			if (sexo == SEXO_MASCULINO) {
				cout << " es padre de ";
			}
			else {
				cout << " es madre de ";
			}
		}
		else if (r->getValor() == TIPO_DESCEDIENTE) {
			if (sexo == SEXO_MASCULINO) {
				cout << " es hijo de ";
			}
			else {
				cout << " es hija de ";
			}
			
		}
		else if (r->getValor() == TIPO_CONYUGE) {
			if (sexo == SEXO_MASCULINO) {
				cout << " es esposo de ";
			}
			else {
				cout << " es esposa de ";
			}
		}
		else if (r->getValor() == TIPO_HERMANO) {
			if (sexo == SEXO_MASCULINO) {
				cout << " es hermano de ";
			}
			else {
				cout << " es hermana de ";
			}
		}
		else if (r->getValor() == TIPO_NIETO) {
			if (sexo == SEXO_MASCULINO) {
				cout << " es nieto de ";
			}
			else {
				cout << " es nieta de ";
			}
		}
		else if (r->getValor() == TIPO_SOBRINO) {
			if (sexo == SEXO_MASCULINO) {
				cout << " es sobrino de ";
			}
			else {
				cout << " es sobrina de ";
			}
		}
		else {
			cout << "[ERROR]NO DEBERIA SUCEDER!!";
		}
		
		if (pRelacionada == NULL) {
			cout << " [Error] ";
		}
		else {
			cout << pRelacionada->getNombre() << endl;
		}
		auxP = auxP->GetSiguiente();
	}
}

PersonaGrafo * GrafoFamiliar::buscarPersonaPorIndiceEnMatriz(int indice) {
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

Lista<RelacionMatriz>* GrafoFamiliar::buscarHermanos(int indice) {
	 

	Lista<RelacionMatriz> * hermanos = new Lista<RelacionMatriz>();
	 
	// para cada padre, extraer hijos
	Lista<RelacionMatriz> * padres = buscarPadres(indice);
	
	//if (indicePaternal1 != -1) {
	if (padres != NULL && !padres->EstaVacia()) {
		 
		Nodo<RelacionMatriz> * auxPadre = padres->GetCabeza();
		while (auxPadre != NULL) {
			//RelacionMatriz * r = auxPadre->GetObjeto();
			int indicePaternal = (auxPadre->GetObjeto())->getIndice();

			Lista<RelacionMatriz> * relacionesPaternal1 = matrizAdyacencia->obtenerCamposEnFila(indicePaternal);
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
			auxPadre = auxPadre->GetSiguiente();
		}
	}
	 
	return hermanos;
}

Lista<RelacionMatriz>* GrafoFamiliar::buscarPadres(int indice)
{
	Lista<RelacionMatriz> * padres = new Lista<RelacionMatriz>();
	Lista<RelacionMatriz> * resultado = matrizAdyacencia->obtenerCamposEnFila(indice);
	if (resultado != NULL && !resultado->EstaVacia()) {
		Nodo<RelacionMatriz> * auxP = resultado->GetCabeza();
		while (auxP != NULL) {
			RelacionMatriz * r = auxP->GetObjeto();
			if (r->getValor() == TIPO_DESCEDIENTE) {
				padres->InsertarUnico(new RelacionMatriz(r->getIndice(), TIPO_DESCEDIENTE));
			}
			auxP = auxP->GetSiguiente();
		}
	}
	return padres;
}

Lista<RelacionMatriz>* GrafoFamiliar::buscarAbuelos(int indice)
{
	Lista<RelacionMatriz> * abuelos = new Lista<RelacionMatriz>();

	Lista<RelacionMatriz> * padres = this->buscarPadres(indice);
	if (padres != NULL && !padres->EstaVacia()) {
		Nodo<RelacionMatriz> * auxPadre = padres->GetCabeza();
		while (auxPadre != NULL) {
			int indicePadre = auxPadre->GetObjeto()->getIndice();
			// sacar los abuelos
			Lista<RelacionMatriz> * abuelosDePadre = this->buscarPadres(indicePadre);
			if (abuelosDePadre != NULL && !abuelosDePadre->EstaVacia()) {
				Nodo<RelacionMatriz> * auxAbuelo = abuelosDePadre->GetCabeza();
				while (auxAbuelo != NULL) {
					int indiceAbuelo = auxAbuelo->GetObjeto()->getIndice();

					// agregar abuelo
					abuelos->InsertarUnico(new RelacionMatriz(indiceAbuelo,TIPO_NIETO));

					auxAbuelo = auxAbuelo->GetSiguiente();
				}
			}

			auxPadre = auxPadre->GetSiguiente();
		}
	}

	return abuelos;
}

Lista<RelacionMatriz>* GrafoFamiliar::buscarTios(int)
{
	return nullptr;
}

void GrafoFamiliar::DesplegarTodo() {
	cout << "Personas: -- > " << endl;
	this->personas->DesplegarLinear();
	cout << "Matrix Adyacente: -->" << endl;
	this->matrizAdyacencia->desplegar();
}

