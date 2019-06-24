#ifndef PILHA_H
#define PILHA_H

#include "LDE.h"

class Pilha : public LDE
{
	private:
		int topo; //Atributo topo da pilha
	public:
		Pilha():LDE(){
		}
		int getTopo();
		void inicializa(int);
		void empilha(int);
		void desempilha();
		void imprimir();
		~Pilha();
};

//Fun��o que obtem o topo da lista
//atrav�s do inicio da lista
int Pilha::getTopo(){
	topo = LDE::getInicio();
	return topo;
}

//Insere primeiro elemento na Pilha Dinamica
void Pilha::inicializa(int num){
	LDE::criarNo(num);
}

//Empilha elemento na pilha din�mica
//atrav�s do m�todo herdado insereInicio da classe LDE
void Pilha::empilha(int num){
	LDE::insereInicio(num);
}

//Desempilha elemento da pilha din�mica
//atrav�s do m�todo herdado removeInicio da classe LDE
void Pilha::desempilha(){
	LDE::removeInicio();
}

//Imprime todos os elementos da pilha din�mica
//atrav�s do m�todo herdado imprimir da classe LDE
void Pilha::imprimir(){
	LDE::imprimir();
}

Pilha::~Pilha(){
	
}
#endif
