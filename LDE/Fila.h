#ifndef FILA_H
#define FILA_H

#include "LDE.h"

class Fila : public LDE
{
	private:
		int primeiro; //Primeiro elemento da Fila din�mica
		int ultimo; //�ltimo elemento da Fila din�mica
	public:
		Fila():LDE(){
		};
		int getPrimeiro();
		int getUltimo();
		void inicializa(int);
		void enfileira(int);
		void desenfileira();
		void imprimir();
		~Fila();
	protected:
};

//Fun��o que obtem o primeiro elemento da fila
//atrav�s do inicio da lista
int Fila::getPrimeiro(){
	primeiro = LDE::getInicio();
	return primeiro;
}

//Fun��o que obtem o ultimo elemento da fila
//atrav�s do fim da lista
int Fila::getUltimo(){
	ultimo = LDE::getFim();
	return ultimo;
}

//Insere primeiro elemento na fila din�mica
void Fila::inicializa(int num){
	LDE::criarNo(num);
}

//Enfileira elemento na fila din�mica
//atrav�s do m�todo herdado insereFim da classe LDE
void Fila::enfileira(int num){
	LDE::insereFim(num);
}

//Desenfileira elemento da fila din�mica
//atrav�s do m�todo herdado removeFim da classe LDE
void Fila::desenfileira(){
	LDE::removeFim();
}

//Imprime todos os elementos da fila din�mica
//atrav�s do m�todo herdado imprimir da classe LDE
void Fila::imprimir(){
	LDE::imprimir();
}

Fila::~Fila(){
	
}
#endif
