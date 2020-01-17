#include <stdio.h>
#include "bib.h"

int procura(int vet[], int tamanho){
	int i, j;
	
			
	for(i = 0; i < tamanho; i++){
		for(j = i + 1; j < tamanho; j++){
	
		if(vet[i] == vet[j]){
			
			return j;
			
		}
	
	}
}
	return -1;
	
}

void removeDoIndice(int vet[], int *tamanho, int indice){
	int i;
	
	for(i = indice; i < *tamanho; i++){
		
		vet[i] = vet[i+1];		
		
}
	(*tamanho)--;
	
}




void imprimir(int vet[], int tamanho){
	int i;
	
	for(i = 0; i < tamanho; i++){
		printf("%d ", vet[i]);
}
	
}



