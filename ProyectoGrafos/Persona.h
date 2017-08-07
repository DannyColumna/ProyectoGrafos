#pragma once
class Persona
{
private:
	char* id;
	char* nombre;
	char* fechaDeNacimiento;

public:
	Persona();
	~Persona();

	void setId(char *);
	char *getId();

	void setNombre(char *);
	char *getNombre();

	void setFechaDeNacimiento(char *);
	char *getFechaDeNacimiento();
};
