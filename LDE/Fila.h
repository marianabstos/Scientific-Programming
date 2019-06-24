#ifndef FILA_H
#define FILA_H

#include "LDE.h"

class Fila : public LDE
{
	private:
		int primeiro; //Primeiro elemento da Fila dinâmica
		int ultimo; //Último elemento da Fila dinâmica
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

//Função que obtem o primeiro elemento da fila
//através do inicio da lista
int Fila::getPrimeiro(){
	primeiro = LDE::getInicio();
	return primeiro;
}

//Função que obtem o ultimo elemento da fila
//através do fim da lista
int Fila::getUltimo(){
	ultimo = LDE::getFim();
	return ultimo;
}

//Insere primeiro elemento na fila dinâmica
void Fila::inicializa(int num){
	LDE::criarNo(num);
}

//Enfileira elemento na fila dinâmica
//através do método herdado insereFim da classe LDE
void Fila::enfileira(int num){
	LDE::insereFim(num);
}

//Desenfileira elemento da fila dinâmica
//através do método herdado removeFim da classe LDE
void Fila::desenfileira(){
	LDE::removeFim();
}

//Imprime todos os elementos da fila dinâmica
//através do método herdado imprimir da classe LDE
void Fila::imprimir(){
	LDE::imprimir();
}

Fila::~Fila(){
	
}
#endif
