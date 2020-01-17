
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Locadora.h"
#define MAX 100



struct filme{
int codigo;
char titulo[100];
int ano;
int quantidade;
char genero[10];
}filmes[MAX];
void lerDadotxt(char *nome_aqr){

FILE *arq;
int i=0;
if((arq=fopen(nome_aqr,"r"))==NULL){
   printf("ERROR: O Arquivo %s não foi encontrado!",nome_aqr);
    return;
}
while(!feof(arq)&&i<MAX){
        fscanf(arq,"%d",&filmes[i].codigo);
       fgets(filmes[i].titulo,100,arq);
       fscanf(arq,"%d",&filmes[i].ano);
       fscanf(arq,"%d",&filmes[i].quantidade);
        fgets(filmes[i].genero,10,arq);
  i++;
}

fclose(arq);
}

int menu(void) {
int c=0;
do {
printf("-- MENU:\n");
printf("\t 1. Locar \n");
printf("\t 2. entrega de filmes \n");
printf("\t 3. busca Por Codigo\n");
printf("\t 4. busca Por nome\n");
printf("\t 5. busca Por ano\n");
printf("\t 6. busca Por genero\n");
printf("\t 7. impressão \n");
printf("\t 8. Sair \n");
printf("-- Digite sua escolha: ");
scanf("%d", &c);
} while(c<=0 || c>8);
getchar();
return c;
}
int buscaPorano(int *ano){
int i=0;
lerDadotxt("entrada.txt");
while(i<MAX){
    if (ano == &filmes[i].ano){
        return i;
    }
    i++;
}
return -1;
}
int ProcuraPorNomes(char *str){
int i,j=0;
lerDadotxt("entrada.txt");
for(i=0; i<MAX;i++){
    if(strstr(filmes[i].titulo,str)){

        i++;
    }
  }
  return i;
}
int buscaPorCod(int *cod){
int i=0;
lerDadotxt("entrada.txt");
while(i<MAX){
    if (cod == &filmes[i].codigo){
        return i;
    }
    i++;
}
return -1;
}
int ProcuraPorGenero(char *str){
int i;
lerDadotxt("entrada.txt");
for(i=0; i<MAX;i++){
    if(strstr(filmes[i].genero,str)){

        i++;
    }
  }
  return i;
}
void Buscacod (void){
int *cod,i;
    printf(" Digite o codigo para ser localizado \n");
   scanf("%d",&cod);
i = buscaPorCod(cod);
    if(i>=0){
printf("\t Codigo : %d", filmes[i].codigo);
printf("\t Titulo: %s", filmes[i].titulo);
printf("\t quntidade para ser locado: %d", filmes[i].quantidade);
printf("\t ano : %d", filmes[i].ano);
printf("\t Genero %s\n", filmes[i].genero);
    }else{
    printf("Filme  nao localizado\n");
    }

}
void locar (void){
int i, *cod;
lerDadotxt("entrada.txt");
printf("informe codigo do filme");
scanf("%d",&cod);
i = buscaPorCod(cod);

filmes[i].quantidade=filmes[i].quantidade-1;

}
void entrega (void){

int i, *cod;
lerDadotxt("entrada.txt");
printf("informe codigo do filme");
scanf("%d",&cod);
i = buscaPorCod(cod);

filmes[i].quantidade=filmes[i].quantidade+1;

}
void ler_string(char palavra[100], int tamanho) {
int i = 0;
char c;
c = getchar();
while ((c != '\n') && (i < tamanho)) {
palavra[i++] = c;
c = getchar();
}
palavra[i] = '\0';
if (c != '\n') {
c = getchar();
while((c != '\n') && (c != EOF)) {
c = getchar();
}
}
}
void ImprimePorNome(void){
 char nome[100];
    int i;
    printf(" Digite o Titulo para ser localizado \n");
    ler_string(nome,100);
    i=ProcuraPorNomes(nome);
    if(i>=0){
printf("\t Codigo : %d", filmes[i].codigo);
printf("\t Titulo: %s", filmes[i].titulo);
printf("\t quntidade para ser locado: %d", filmes[i].quantidade);
printf("\t ano : %d", filmes[i].ano);
printf("\t Genero %s\n", filmes[i].genero);
    }else{
    printf("Filme  nao localizado\n");

    }

}
void BuscaAno (void){
int *cod,i;
    printf(" Digite o Ano para ser localizado \n");
   scanf("%d",&cod);
i = buscaPorano(cod);
    if(i>=0){
printf("\t Codigo : %d", filmes[i].codigo);
printf("\t Titulo: %s", filmes[i].titulo);
printf("\t quntidade para ser locado: %d", filmes[i].quantidade);
printf("\t ano : %d", filmes[i].ano);
printf("\t Genero %s\n", filmes[i].genero);
    }else{
    printf("Filme  nao localizado\n");
    }

}
void ImprimePorGenero(void){
 char nome[10];
    int i;
    printf(" Digite o Titulo para ser localizado \n");
    ler_string(nome,10);
    i=ProcuraPorGenero(nome);
    if(i>=0){
printf("\t Codigo : %d", filmes[i].codigo);
printf("\t Titulo: %s", filmes[i].titulo);
printf("\t quntidade para ser locado: %d", filmes[i].quantidade);
printf("\t ano : %d", filmes[i].ano);
printf("\t Genero %s\n", filmes[i].genero);
    }else{
    printf("Filme  nao localizado\n");

    }

}
void impress(void){
int i;
for( i=0; i < MAX; i++)
{
printf("\t Codigo : %d", filmes[i].codigo);
printf("\t Titulo: %s", filmes[i].titulo);
printf("\t quntidade para ser locado: %d", filmes[i].quantidade);
printf("\t ano : %d", filmes[i].ano);
printf("\t Genero %s\n", filmes[i].genero);


}
}
