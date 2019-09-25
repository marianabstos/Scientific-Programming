#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <cmath>
#define MAX 70
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


float funcao_a(float x){
	return x*x;
}

float derivada_funcao_a(float x){
	return 2*x;
}

float funcao_b(float x){
	return ((x*x*x) - (2*(x*x)) + 2);
}

float derivada_funcao_b(float x){
	return ((3*(x*x)) - (4*x));
}

void newton_raphson_a(int num, float beta){
	float x[MAX];
	float f[MAX];
	x[0] = num;
	f[0] = funcao_a(x[0]);
	
	int cont=0;
	
	#pragma omp parallel for
	for(int i=0; f[i] > 0.0; i++){
		
		x[i+1] = (x[i] - (beta*f[i]*(1/derivada_funcao_a(x[i]))));
		i=i+1;
		f[i] = funcao_a(x[i]);
		
		if (i == MAX){
			break;
		}
		cont++;
	}
	
	printf("#########################################\n");
	printf ("f(%d) = %.5f\n", cont-1, f[cont-1]);
	printf ("x(%d) = %.5f\n", cont-1, x[cont-1]);
	printf ("Taxa aprendizado = %.1f\n", beta);
	printf("#########################################\n");
}

void newton_raphson_b(int num, float beta){
	float x[MAX];
	float f[MAX];
	x[0] = num;
	f[0] = funcao_b(x[0]);
	
	int cont=0;
	
	#pragma omp parallel for
	for(int i=0; f[i] > 0.0; i++){
		x[i+1] = (x[i] - (beta*f[i]*(1/derivada_funcao_b(x[i]))));
		i=i+1;
		f[i] = funcao_b(x[i]);
		
		if (i == MAX){
			break;
		}
		
		cont++;
		
	}
	
	printf("#########################################\n");
	printf ("f(%d) = %.5f\n", cont-1, f[cont-1]);
	printf ("x(%d) = %.5f\n", cont-1, x[cont-1]);
	printf ("Taxa aprendizado = %.1f\n", beta);
	printf("#########################################\n");
	
}

int main(int argc, char** argv) {
	
	/*Equação A*/
	printf("Equacao A\n");
	newton_raphson_a(2,0.1);
	newton_raphson_a(2,0.2);
	newton_raphson_a(2,0.3);
	newton_raphson_a(2,0.4);
	newton_raphson_a(2,0.5);
	newton_raphson_a(2,0.6);
	newton_raphson_a(2,0.7);
	newton_raphson_a(2,0.8);
	newton_raphson_a(2,0.9);

	/*Equação B*/
	printf("Equacao B\n");
	newton_raphson_b(2,0.1);
	newton_raphson_b(2,0.2);
	newton_raphson_b(2,0.3);
	newton_raphson_b(2,0.4);
	newton_raphson_b(2,0.5);
	newton_raphson_b(2,0.6);
	newton_raphson_b(2,0.7);
	newton_raphson_b(2,0.8);
	newton_raphson_b(2,0.9);
	
	return 0;
}
