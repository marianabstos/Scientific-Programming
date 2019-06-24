#ifndef PILHA_H
#define PILHA_H
#define MAX 7

#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

class Pilha
{
	private:
		char s[MAX]; //Vetor de caracteres
		int topo; //Inteiro que indicar� a posi��o topo da pilha
		
	public:
		Pilha();
		void inicializa();
		void empilha(string);
		string desempilha();
		char* getS();
		int getTopo();
};

Pilha::Pilha (){
}

char* Pilha::getS(){
	return s; //Retorna os caracteres da pilha
}

int Pilha::getTopo (){
	return topo; //Retorna a posi��o do topo
}

void Pilha::inicializa(){
	topo =-1; //Inicializa topo com -1 para n�o estourar o tamanho do vetor
}

void Pilha::empilha(string palavra){
	
	int tam = palavra.length(); //Seta tam com o tamanho da palavra q deve ser empilhada
	for(int i=0; i<tam; i++){ //For para empilhar palavra
		topo++; //Incrementa topo, dado que ser� inserido um novo elemento
		s[topo] = palavra[i]; //insere no topo o elemento
	}

}

string Pilha::desempilha(){
	
	string palavra; //Vetor que receber� letras desempilhadas
	int tam; //tamanho da palavra empilhada
	
	tam = strlen(s); //atribui a tam o valor do tamanho da palvra empilhada
	for(int i=0; i<tam; i++){ //for para desempilhar letras
		palavra[i] = s[topo];  //retira letra do topo e insere na string palavra
		topo--; //atualiza vari�vel topo
	}

	return palavra.c_str();
}

#endif


