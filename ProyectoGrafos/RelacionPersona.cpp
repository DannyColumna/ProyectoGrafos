#include "stdafx.h"
#include "RelacionPersona.h"


RelacionPersona::RelacionPersona()
{
}


RelacionPersona::~RelacionPersona()
{
}

RelacionPersona::RelacionPersona(char * Id, int tipoRelacion) {
	this->relacionPersonaId = Id;
	this->tipoRelacion = tipoRelacion;
}

void RelacionPersona::setTipo(int relacion)
{
	this->tipoRelacion = relacion;
}

void RelacionPersona::setId(char *id)
{
	this->relacionPersonaId = id;
}

int RelacionPersona::getTipo()
{
	return this->tipoRelacion;
}

char * RelacionPersona::getId()
{
	return this->relacionPersonaId;
}