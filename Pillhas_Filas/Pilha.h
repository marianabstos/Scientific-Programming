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
		char s[MAX];
		int topo;
		
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
	return s;
}

int Pilha::getTopo (){
	return topo;
}

void Pilha::inicializa(){
	topo =-1;
}

void Pilha::empilha(string palavra){
	
	int tam = palavra.length();
	for(int i=0; i<tam; i++){
		topo++;
		s[topo] = palavra[i];
	}

}

string Pilha::desempilha(){
	
	string palavra;
	int tam;
	
	tam = strlen(s);
	for(int i=0; i<tam; i++){
		palavra[i] = s[topo];
		topo--;
	}

	return palavra.c_str();
}

#endif


