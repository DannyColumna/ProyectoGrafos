#pragma once
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
};
