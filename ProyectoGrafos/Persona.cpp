#include "stdafx.h"
#include "Persona.h"


Persona::Persona()
{
}


Persona::~Persona()
{
}

void Persona::setId(char * ID)
{
	this->id = ID;
}

char * Persona::getId()
{
	return this->id;
}

void Persona::setNombre(char * nombre)
{
	this->nombre = nombre;
}

char * Persona::getNombre()
{
	return this->nombre;
}

void Persona::setFechaDeNacimiento(char *fechaNacimiento)
{
	this->fechaDeNacimiento = fechaNacimiento;
}

char * Persona::getFechaDeNacimiento()
{

	return this->fechaDeNacimiento;
}
