#ifndef LDE_H
#define LDE_H

#include "No.h"
#include <iostream>
#include <exception>
using namespace std;

class LDE : public no
{
	private:
		no *inicio; //No que identifica o inicio da lista
		no *fim; //No que identifica o fim da lista
		 
	public:
		LDE();
		int getInicio();
		int getFim();
		void criarNo(int);
		void insereInicio(int);
		void insereFim(int);
		void removeInicio();
		void removeFim();
		int buscar(int);
		void imprimir();
		~LDE();
};

//Inicializa os ponteiros da lista
LDE::LDE(){
	inicio = NULL;
	fim = NULL;
}

//Retorna o valor da posição de inicio da lista
//para ser acessado por outras classes
int LDE::getInicio(){
	return inicio->numero;
}

//Retorna o valor da posição do fim da lista
//para ser acessado por outras classes
int LDE::getFim(){
	return fim->numero;
}

//Procedimento utilizado para criar o primeiro Nó da Lista
//evita conferir se é o primeiro elemento a cada inserção
void LDE::criarNo(int num){
	no *novo = new no; //cria novo no
	
	novo->numero = num; //atribui o elemento do novo no
	novo->proximo = NULL; //atribui ao no proximo valor null pois só exite um nó na lista
	
	inicio = novo; //atribui o no novo ao inicio
	fim = novo; //atribui o no novo ao fim
	novo = NULL; //Reseta os endereços dos ponteiros, dado que o no novo já está na lista como inicio e fim
	
}

//Procedimento utilizado para inserir elementos
//no inicio da fila
void LDE::insereInicio(int num){
	no *novo = new no; //cria novo no
	novo->numero = num; //atribui o elemento do novo no
	novo->proximo = inicio; //aponta o proximo para o inicio, dado que este nó será o inicio
	inicio = novo; //atualiza o inicio da lista com o novo no
}

//Procedimento utilizado para inserir elementos
//no fim da lista
void LDE::insereFim(int num){
	no *novo = new no; //cria novo no
	novo->numero = num; //atribui o elemento do novo no
	novo->proximo = NULL; //Atribui null ao ponteiro proximo do no novo, dado que este será o ultimo da lista
	fim->proximo = novo; //
	fim = novo; // atualiza o fim da lista com o novo no
}

//Procedimento utilizado para remover elementos
//do inicio da lista
void LDE::removeInicio(){
	no *novo = new no; //cria novo no
	novo = inicio; //atribui a novo o no de inicio
	inicio = inicio->proximo; //atualiza inicio como o proximo valor
	delete novo; // deleta o primeiro no
}

//Procedimento utilizado para remover elementos
//do fim da lista
void LDE::removeFim(){
	no *atual = new no; //cria no atual
	no *anterior = new no; //cria no anterior
	atual=inicio; //Atribui a atual o no de inicio
	while(atual->proximo != NULL){ //Enquanto existir proximo 
		anterior=atual; //atualiza o anterior como atual
		atual=atual->proximo; //atualiza atual como próximo
	}
	anterior->proximo=NULL;	 //Atualiza proximo como NULL, dado que esse é o ultimo nó
	fim = anterior; //atualiza fim com nó anterior, removendo o atual (último nó)
}

//Função utilizada para buscar elementos
//na lista através de um dado elemento
int LDE::buscar(int num){
	no *novo = new no;
	novo = inicio;
	bool flag = false;
	
	while(novo != NULL){
		if(novo->numero == num){
			flag = true;
			cout<<"Numero encontrado: "<<novo->numero<<endl;
			break;
		}
		novo=novo->proximo;
	}
	
	if(!flag)
		cout<<"O numero "<<num<<" nao foi encontrado"<<endl;
}

//Função utilizada para imprimir todos os
//elementos da lista
void LDE::imprimir(){
	no *novo = new no; //cria no novo
	novo = inicio; //Atribui ao no novo o inicio da lista
	
	try{
		while(novo != NULL){
			cout<<novo->numero<<endl;
			novo = novo->proximo; //Percorre toda a lista
		}
	}
	catch(const exception &e){
		cout<<"VAZIO!!"<<endl;
	}
}

LDE::~LDE(){
	
}

#endif
