/*
Autor = Mariana Bastos dos Santos

Trabalho feito para a disciplina de Programação Científica
no Centro Universitário da FEI

*/

#include <iostream>
#include <string>
#include "LDE.h"
#include "Pilha.h"
#include "Fila.h"


int main(int argc, char** argv) {

string letra;

cout<<"(p)ilha ou (f)ila: ";
cin>>letra;

if(letra == "p"){
	
	cout<<"---------- PILHA ---------------------"<<endl;
	
	Pilha p;
	
	cout<<"Empilha 10"<<endl;
	p.inicializa(10);
	cout<<"Empilha 2"<<endl;
	p.empilha(2);
	cout<<"Empilha 3"<<endl;
	p.empilha(3);
	cout<<"Empilha 4"<<endl;
	p.empilha(4);
	
	cout<<"Imprimindo a pilha..."<<endl;
	p.imprimir();
	
	cout<<"Desempilhando..."<<endl;
	cout<<"Topo: "<<p.getTopo()<<endl;
	p.desempilha();
	cout<<"Topo atualizado..."<<endl;
	cout<<"Topo: "<<p.getTopo()<<endl;
	p.imprimir();
	
	cout<<"Desempilhando..."<<endl;
	cout<<"Topo: "<<p.getTopo()<<endl;
	p.desempilha();
	cout<<"Topo atualizado..."<<endl;
	cout<<"Topo: "<<p.getTopo()<<endl;
	p.imprimir();
	
	cout<<"Desempilhando..."<<endl;
	cout<<"Topo: "<<p.getTopo()<<endl;
	p.desempilha();
	cout<<"Topo atualizado..."<<endl;
	cout<<"Topo: "<<p.getTopo()<<endl;
	p.imprimir();
	
	cout<<"Desempilhando..."<<endl;
	cout<<"Topo: "<<p.getTopo()<<endl;
	p.desempilha();
	cout<<"Topo atualizado..."<<endl;
	cout<<"Topo: "<<p.getTopo()<<endl;
	p.imprimir();
}

if(letra == "f"){
	
	cout<<"---------- FILA ---------------------"<<endl;
	
	Fila f;
	
	cout<<"Enfileira 10"<<endl;
	f.inicializa(10);
	cout<<"Enfileira 2"<<endl;
	f.enfileira(2);
	cout<<"Enfileira 3"<<endl;
	f.enfileira(3);
	cout<<"Enfileira 4"<<endl;
	f.enfileira(4);
	
	cout<<"Imprimindo a fila..."<<endl;
	f.imprimir();
	
	cout<<"desenfileirando..."<<endl;
	cout<<"Primeiro: "<<f.getPrimeiro()<<endl;
	cout<<"Ultimo: "<<f.getUltimo()<<endl;
	f.desenfileira();
	cout<<"Primeiro e Ultimo atualizado..."<<endl;
	cout<<"Primeiro: "<<f.getPrimeiro()<<endl;
	cout<<"Ultimo: "<<f.getUltimo()<<endl;
	f.imprimir();
	
	cout<<"desenfileirando..."<<endl;
	cout<<"Primeiro: "<<f.getPrimeiro()<<endl;
	cout<<"Ultimo: "<<f.getUltimo()<<endl;
	f.desenfileira();
	cout<<"Primeiro e Ultimo atualizado..."<<endl;
	cout<<"Primeiro: "<<f.getPrimeiro()<<endl;
	cout<<"Ultimo: "<<f.getUltimo()<<endl;
	f.imprimir();
	
	cout<<"desenfileirando..."<<endl;
	cout<<"Primeiro: "<<f.getPrimeiro()<<endl;
	cout<<"Ultimo: "<<f.getUltimo()<<endl;
	f.desenfileira();
	cout<<"Primeiro e Ultimo atualizado..."<<endl;
	cout<<"Primeiro: "<<f.getPrimeiro()<<endl;
	cout<<"Ultimo: "<<f.getUltimo()<<endl;
	f.imprimir();
	
	cout<<"desenfileirando..."<<endl;
	cout<<"Primeiro: "<<f.getPrimeiro()<<endl;
	cout<<"Ultimo: "<<f.getUltimo()<<endl;
	f.desenfileira();
	cout<<"Primeiro e Ultimo atualizado..."<<endl;
	cout<<"Primeiro: "<<f.getPrimeiro()<<endl;
	cout<<"Ultimo: "<<f.getUltimo()<<endl;
	f.imprimir();
	
	cout<<"desenfileirando..."<<endl;
	cout<<"Primeiro: "<<f.getPrimeiro()<<endl;
	cout<<"Ultimo: "<<f.getUltimo()<<endl;
	f.desenfileira();
	cout<<"Primeiro e Ultimo atualizado..."<<endl;
	cout<<"Primeiro: "<<f.getPrimeiro()<<endl;
	cout<<"Ultimo: "<<f.getUltimo()<<endl;
	f.imprimir();
	
	
}

	
	system("PAUSE");
	return 0;
}
