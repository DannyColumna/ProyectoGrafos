#pragma once
class RelacionMatriz
{
private:
	int indice;
	int valor;

public:
	RelacionMatriz();
	RelacionMatriz(int, int);
	~RelacionMatriz();

	void setIndice(int);
	int getIndice();

	void setValor(int);
	int getValor();

	//bool operator==(RelacionMatriz& der)const;
	bool operator==(RelacionMatriz der)const;
};

