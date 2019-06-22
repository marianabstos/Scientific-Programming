#ifndef FILA_H
#define FILA_H

#define MAX 10

class Fila
{
	private:
		int primeiro;
		int ultimo;
		int tamanho;
		string pessoas[MAX];
		
	public:
		Fila();
		int getPrimeiro();
		int getUltimo();
		int getTamanho();
		string * getPessoas();
		void inicializa();
		void enfileira(string);
		string desenfileira();
};

Fila::Fila(){
	
}

void Fila::inicializa(){
	primeiro =-1;
	ultimo = -1;
	tamanho = 0;
	
}

int Fila::getPrimeiro(){
	return primeiro;
}

int Fila::getUltimo(){
	return ultimo;
}

int Fila::getTamanho(){
	return tamanho;
}

string * Fila::getPessoas(){
	return pessoas;
}

void Fila::enfileira(string nomes){
	ultimo++;
	pessoas[ultimo] = nomes;
	tamanho++;
}

string Fila::desenfileira(){
	
	string nome;
	
	primeiro++;
	nome = pessoas[primeiro];
	
	return nome;
}

#endif
