#ifndef FILA_H
#define FILA_H

#define MAX 10

class Fila
{
	private:
		int primeiro; //posi��o do primeiro elemento da fila
		int ultimo; //posi��o do �ltimo elemento da fila
		int tamanho; //tamanho da fila 
		string pessoas[MAX]; //string de pessoas que ser�o inseridas na fila
		
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
//Inicializa atributos para n�o estourar valor do vetor 
//ou acessar endere�o errado
void Fila::inicializa(){
	primeiro =-1;
	ultimo = -1;
	tamanho = 0;
	
}

int Fila::getPrimeiro(){
	return primeiro; //retorna posi��o do primeiro elemento da fila
}

int Fila::getUltimo(){
	return ultimo; //retorna posi��o do ultimo elemento da fila
}

int Fila::getTamanho(){
	return tamanho; //retorna tamanho da fila
}

string * Fila::getPessoas(){
	return pessoas; //retorna pessoas da fila
}

void Fila::enfileira(string nomes){
	ultimo++; //atualiza a ultima posi��o da fila, dado que est� sendo inserido um elemento
	pessoas[ultimo] = nomes; //insere no final da fila o elemento
	tamanho++; //atualiza tamanho da fila
}

string Fila::desenfileira(){
	
	string nome; //nome da pessoa que esta saindo da fila
	
	primeiro++; //atualiza primeiro elemento da fila, dado que est� sendo retirado um elemento
	nome = pessoas[primeiro]; //atualiza nome de quem saiu da fila
	
	return nome; //retorna nome de quem saiu da fila
}

#endif
