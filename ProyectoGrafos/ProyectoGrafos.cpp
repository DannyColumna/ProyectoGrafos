// Grafos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GrafoFamiliar.h"


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

	Persona * dannySr = new Persona();
	dannySr->setId("002");
	dannySr->setNombre("Danny Columna Sr");
	dannySr->setFechaDeNacimiento("1960");

	grafos->AgregarPersona(ale, NULL);

	Lista<RelacionPersona> * relaciones = new Lista<RelacionPersona>();
	RelacionPersona * r = new RelacionPersona(ale->getId(), TIPO_PATERNAL);
	relaciones->InsertarFinal(r);
	grafos->AgregarPersona(dannySr, relaciones);


	grafos->DesplegarTodo();

	return 0;
}



