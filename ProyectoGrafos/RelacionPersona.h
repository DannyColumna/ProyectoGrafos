#pragma once
 

class RelacionPersona
{


private:
	char *relacionPersonaId;
    int tipoRelacion;
public:
	RelacionPersona();
	~RelacionPersona();
	 
	RelacionPersona(char*, int);

	void setTipo(int);
	void setId(char*);

	int getTipo();
	char* getId();


};
