#include <stdio.h>
#include "bib.h"
#define MAX 100
#include "bib.c"

int main(int argc, char **argv){
int vetor[MAX] = {1,2,4,2,6,8,2,8,10,6}, tamanho = 10, indice;


do{

	indice = procura(vetor, tamanho);

		if(indice != -1){

			removeDoIndice(vetor, &tamanho, indice);

		}

}while(indice != -1);


imprimir(vetor, tamanho);

	return 0;
}

