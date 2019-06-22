#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Pilha.h"
#include "Fila.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
	
	//Início Pilha
	
	cout<<"PILHA"<<endl;
	cout<<"###############"<<endl;
	
	Pilha p;
	p.inicializa();
	p.empilha("Mariana");
	
	char* palavra;
	int topo;
	
	topo = p.getTopo();
	palavra = p.getS();
	
	for (int i=0; i<7; i++){
		cout << "Empilha: "<<palavra[i]<<endl;
	}
	
	
	printf("Topo: %d\n", topo);
	printf("Letra Topo: %c\n", palavra[topo]);
	
	string word;
	word = p.desempilha();
	
	cout << "Desempilha: "<<word<<endl;
	
	cout<<"###############"<<endl;
	
	//Fim pilha
	
	//--------------------------------------------
	
	//Início Fila
	cout<<endl;
	cout<<"Fila"<<endl;
	cout<<"###############"<<endl;
	
	fflush(stdin);	

	string v[8];
	
	v[0] = "Mariana";
	v[1] = "Joao";
	v[2] = "Pedro";
	v[3] = "Maria";
	v[4] = "Juliana";
	v[5] = "Sofia";
	v[6] = "Enzo";
	v[7] = "Pietra";
	
	Fila f;
	
	f.inicializa();
	
	for(int i=0; i<8; i++){
		f.enfileira(v[i].c_str());
	}
	
	string * nomes;
	
	nomes = f.getPessoas();
	
	for(int i=0; i<f.getTamanho();i++){
		printf("Enfileirando...\nFila[%d] = %s\n\n", i, nomes[i].c_str());	
	}
	
	cout<<endl<<endl;
	
	
	string nome;
	
	for(int i=0; i<f.getTamanho(); i++){
		nomes = f.getPessoas();
		nome = 	f.desenfileira();
		printf("Fila[%d] = %s\n Desenfileirando...\n Nome = %s\n\n", i, nomes[i].c_str(), nome.c_str());
	}
	
	cout<<"###############"<<endl;
	
	//Fim Fila
	
	system("pause");
	return 0;
}

