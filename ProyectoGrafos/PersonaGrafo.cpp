#include "stdafx.h"
#include "PersonaGrafo.h"


PersonaGrafo::PersonaGrafo()
{
}

PersonaGrafo::PersonaGrafo(int indice, char* ID, char* nombreCompleto, char* fechaNacimiento, char sexo)
{
	this->indiceEnMatriz = indice;
	this->ID = ID;
	this->nombre = nombreCompleto;
	this->fechaNacimiento = fechaNacimiento;
	this->sexo = sexo;
}

PersonaGrafo::~PersonaGrafo()
{
}

int PersonaGrafo::getIndiceEnMatriz()
{
	return this->indiceEnMatriz;
}

void PersonaGrafo::setId(char *ID)
{
	this->ID = ID;
}

void PersonaGrafo::setNombre(char *nombreCompleto)
{
	this->nombre = nombreCompleto;
}

void PersonaGrafo::setFechaNacimiento(char *fechaNacimiento)
{
	this->fechaNacimiento = fechaNacimiento;
}

char * PersonaGrafo::getId() 
{
	return this->ID;
}

char * PersonaGrafo::getNombre()
{
	return this->nombre;
}

char * PersonaGrafo::getFechaNacimiento() {
	return this->fechaNacimiento;
}

void PersonaGrafo::setSexo(char sexo)
{
	this->sexo = sexo;
}

char  PersonaGrafo::getSexo()
{
	return this->sexo;
}

//bool PersonaGrafo::operator==(PersonaGrafo & der) const
//{
//	return strcmp(this->ID, der.ID) == 0;
//}

bool PersonaGrafo::operator==(PersonaGrafo der)
{
	return strcmp(this->ID, der.ID) == 0;
}

 


ostream& operator<<(ostream& os, const PersonaGrafo & pg)
{
	os << "{" << pg.indiceEnMatriz << "," << pg.ID << "," << pg.nombre << "," << pg.fechaNacimiento << "}";
	return os;
}

ostream& operator<<(ostream& os,  PersonaGrafo * pg)
{
	os << "{" << pg->indiceEnMatriz << "," << pg->ID << "," << pg->nombre << "," << pg->fechaNacimiento << "}";
	return os;
}


