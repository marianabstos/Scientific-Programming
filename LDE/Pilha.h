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

//Função que obtem o topo da lista
//através do inicio da lista
int Pilha::getTopo(){
	topo = LDE::getInicio();
	return topo;
}

//Insere primeiro elemento na Pilha Dinamica
void Pilha::inicializa(int num){
	LDE::criarNo(num);
}

//Empilha elemento na pilha dinâmica
//através do método herdado insereInicio da classe LDE
void Pilha::empilha(int num){
	LDE::insereInicio(num);
}

//Desempilha elemento da pilha dinâmica
//através do método herdado removeInicio da classe LDE
void Pilha::desempilha(){
	LDE::removeInicio();
}

//Imprime todos os elementos da pilha dinâmica
//através do método herdado imprimir da classe LDE
void Pilha::imprimir(){
	LDE::imprimir();
}

Pilha::~Pilha(){
	
}
#endif
