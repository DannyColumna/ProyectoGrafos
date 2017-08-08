#pragma once
#include "stdafx.h"
class Persona
{
private:
	char* id;
	char* nombre;
	char* fechaDeNacimiento;
	char sexo;
public:
	Persona();
	~Persona();

	void setId(char *);
	char *getId();

	void setSexo(char );
	char getSexo();

	void setNombre(char *);
	char *getNombre();

    void setFechaDeNacimiento(char *);
	char *getFechaDeNacimiento();
	friend ostream& operator<<(ostream& os, const Persona p);
	friend ostream& operator<<(ostream& os, const Persona* p);
	 
};
