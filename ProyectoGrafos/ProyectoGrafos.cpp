// Grafos.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include "GrafoFamiliar.h"
#include "Lista.h"
#include "Nodo.h"

void Menu() {
	cout << "\n" << "1. Agregar persona. " << endl;
	cout << "2. Editar persona. " << endl;
	cout << "3. Eliminar persona.  " << endl;
	cout << "4. Buscar persona. " << endl;
	cout << "5. Desplegar persona. " << endl;
	cout << "\n" << "Ingrese la opcion: " << endl;
}

void TituloDelProyecto() {
	cout << "\t\t\t\t\t" << "PROYECTO 2: ESTRUCTURAS DE DATOS" << endl;
	cout << "\n" << "HERENCIA FAMILIAR --> UTILIZANDO GRAFOS" << endl;
	cout << "Representacion de Grafos dirigidos." << endl;
}

void Opcion() {
	cout << "\n" << "Menu: " << endl;
	int opcion;
	Menu();
	do {
		cin >> opcion;
		switch (opcion) {
		case 1:
			cout << "1. Agregar persona: " << endl;
			cout << "\n" << endl;
			break;
		case 2:
			cout << "2. Editar persona: " << endl;
			cout << "\n" << endl;
			break;
		case 3:
			cout << "3. Eliminar persona: " << endl;
			cout << "\n" << endl;
			break;
		case 4:
			cout << "4. Buscar persona: " << endl;
			cout << "\n" << endl;
			break;
		case 5:
			cout << "5. Desplegar persona: " << endl;
			cout << "\n" << endl;
			break;
		default: cout << "Opcion no valida..." << endl;
			cout << "\n" << endl;
			break;
		}
	} while (opcion != 7);
}

int main()
{
	GrafoFamiliar *grafos = new GrafoFamiliar();

	Persona * ale = new Persona();
	ale->setId("001");
	ale->setNombre("Alejandro Columna");
	ale->setFechaDeNacimiento("1998");
	ale->setSexo(SEXO_MASCULINO);

	Persona * geo = new Persona();
	geo->setId("002");
	geo->setNombre("Geovanny Columna");
	geo->setFechaDeNacimiento("2003");
	geo->setSexo(SEXO_MASCULINO);

	Persona * dannySr = new Persona();
	dannySr->setId("003");
	dannySr->setNombre("Danny Columna Sr");
	dannySr->setFechaDeNacimiento("1971");
	dannySr->setSexo(SEXO_MASCULINO);

	Persona * patricia = new Persona();
	patricia->setSexo(SEXO_FEMENINO);
	patricia->setId("004");
	patricia->setNombre("Patricia Segura");
	patricia->setFechaDeNacimiento("1974");

	grafos->AgregarPersona(ale, NULL);
	grafos->AgregarPersona(geo, NULL);

	Lista<RelacionPersona> * relaciones = new Lista<RelacionPersona>();
	RelacionPersona * r1 = new RelacionPersona(ale->getId(), TIPO_PATERNAL);
	RelacionPersona * r2 = new RelacionPersona(geo->getId(), TIPO_PATERNAL);
	relaciones->InsertarFinal(r1);
	relaciones->InsertarFinal(r2);
	grafos->AgregarPersona(dannySr, relaciones);
	//delete relaciones;

	Lista<RelacionPersona> * relaciones2 = new Lista<RelacionPersona>();
	//RelacionPersona * r3 = new RelacionPersona(dannySr->getId(), TIPO_CONYUGE);
	relaciones2->InsertarFinal(new RelacionPersona(dannySr->getId(), TIPO_CONYUGE));
	relaciones2->InsertarFinal(new RelacionPersona(ale->getId(), TIPO_PATERNAL));
	relaciones2->InsertarFinal(new RelacionPersona(geo->getId(), TIPO_PATERNAL));
	grafos->AgregarPersona(patricia, relaciones2);


	//abuelo
	Persona * vidal = new Persona();
	vidal->setSexo(SEXO_MASCULINO);
	vidal->setId("005");
	vidal->setNombre("Vidal Segura");
	vidal->setFechaDeNacimiento("1944");

	Lista<RelacionPersona> * relaciones3 = new Lista<RelacionPersona>();
	RelacionPersona * r4 = new RelacionPersona(patricia->getId(), TIPO_PATERNAL);
	relaciones3->InsertarFinal(r4);

	grafos->AgregarPersona(vidal, relaciones3);


	grafos->DesplegarTodo();
	cout << "----" << endl;
	grafos->DesplegarPorPersona();
	
	cout << "\nEditando " << ale->getNombre() << endl;
	ale->setNombre("carlos");
	grafos->EditarPersona(ale->getId(), ale);
	grafos->DesplegarPorPersona();

	cout << "\nEditando  relacion (divorcio)" << dannySr->getNombre() << endl;
	grafos->EditarRelacionPersona(dannySr->getId(), new RelacionPersona(patricia->getId(), TIPO_NINGUNO));
	grafos->DesplegarPorPersona();

	cout << "\nBuscando por ID " << geo->getId() << endl;
	grafos->BuscarPersona(geo->getId());
	//grafos->DesplegarPorPersona();


	cout << "\nEliminando " << dannySr->getNombre() << endl;
	grafos->EliminarPersona(dannySr->getId());
	grafos->DesplegarPorPersona();

	//Menu();
	//Opcion();
	return 0;
}



