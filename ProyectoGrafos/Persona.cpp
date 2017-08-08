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


void Persona::setSexo(char sexo)
{
	this->sexo = sexo;
}

char  Persona::getSexo()
{
	return this->sexo;
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



ostream& operator<<(ostream& os, const Persona  p)
{
	os << "{" <<  p.id << "," << p.nombre << ","<< p.fechaDeNacimiento << "}";
	return os;
}

ostream& operator<<(ostream& os, const Persona * p)
{
	os << "{" << p->id << "," << p->nombre << "," << p->fechaDeNacimiento << "}";
	return os;
}

