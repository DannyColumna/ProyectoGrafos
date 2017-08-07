#pragma once
#include "stdafx.h"
class PersonaGrafo
{
private:
	int indiceEnMatriz;
	char * ID;
	char * nombre;
	char * fechaNacimiento;

public:
	PersonaGrafo();
	PersonaGrafo(int, char*, char*, char*);
	~PersonaGrafo();

	int getIndiceEnMatriz();

	void setId(char *);
	void setNombre(char *);
	void setFechaNacimiento(char *);

	char *getId();
	char *getNombre();
	char *getFechaNacimiento();
	friend ostream& operator<<(ostream& os, const PersonaGrafo& pg);
	friend ostream& operator<<(ostream& os,  PersonaGrafo* pg);
};
