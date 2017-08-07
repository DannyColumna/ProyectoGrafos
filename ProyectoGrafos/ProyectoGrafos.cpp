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

	Persona * geo = new Persona();
	geo->setId("002");
	geo->setNombre("Geovanny Columna");
	geo->setFechaDeNacimiento("2003");

	Persona * dannySr = new Persona();
	dannySr->setId("003");
	dannySr->setNombre("Danny Columna Sr");
	dannySr->setFechaDeNacimiento("1960");

	Persona * patricia = new Persona();
	patricia->setId("004");
	patricia->setNombre("Patricia Segura");
	patricia->setFechaDeNacimiento("1962");

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
	RelacionPersona * r3 = new RelacionPersona(dannySr->getId(), TIPO_CONYUGE);
	relaciones2->InsertarFinal(r3);
	grafos->AgregarPersona(patricia, relaciones2);


	grafos->DesplegarTodo();
	cout << "----" << endl;
	grafos->DesplegarPorPersona();
	
	return 0;
}



