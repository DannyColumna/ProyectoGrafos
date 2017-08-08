#pragma once
#include "stdafx.h"
class PersonaGrafo
{
private:
	int indiceEnMatriz;
	char * ID;
	char * nombre;
	char * fechaNacimiento;
	char sexo;
public:
	PersonaGrafo();
	PersonaGrafo(int, char*, char*, char*,char);
	~PersonaGrafo();

	int getIndiceEnMatriz();

	void setId(char *);
	void setNombre(char *);
	void setFechaNacimiento(char *);

	char *getId();
	char *getNombre();
	char *getFechaNacimiento();

	void setSexo(char);
	char getSexo();

	friend ostream& operator<<(ostream& os, const PersonaGrafo& pg);
	friend ostream& operator<<(ostream& os,  PersonaGrafo* pg);
    //bool operator==(PersonaGrafo& der)const;
	bool operator==(PersonaGrafo der);
};
