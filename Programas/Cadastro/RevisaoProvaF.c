#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RevisaoProva.h"
#define MAX 100

struct end {
char nome[31];
char rua[41];
char cidade[21];
char estado[3];
unsigned long int cep;
} info[MAX];

void cria_lista(void) {
int i;
for( i=0; i<MAX; i++)
info[i].nome[0]='\0';
}

int menu(void) {
int c=0;
do {
printf("-- MENU:\n");
printf("\t 1. Inserir um nome\n");
printf("\t 2. Excluir um nome\n");
printf("\t 3. Listar o arquivo\n");
printf("\t 4. Apaga por Nome \n");
printf("\t 5. Imprimir por nome\n");
printf("\t 6. Imprime por Nomes \n");
printf("\t 7. Ordenar os arquivo \n");
printf("\t 8. Sair \n");
printf("-- Digite sua escolha: ");
scanf("%d", &c);
} while(c<=0 || c>8);
getchar();
return c;
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

void insere(void) {
int posicao;
char nome[31];
printf("Digite o nome  a ser insirido:  ");
ler_string(nome,30);
posicao=BuscaPorNome(nome);
if(posicao<0){
posicao=livre();
if(posicao == -1) {
printf("\nEstrutura Cheia!!");
return;
}

printf("-- Registro %d:\n", posicao);

strcpy(info[posicao].nome,nome);

printf("\t Rua: ");
ler_string(info[posicao].rua, 40);
printf("\t Cidade: ");
ler_string(info[posicao].cidade, 20);
printf("\t Estado: ");
ler_string(info[posicao].estado, 2);
printf("\t CEP: ");
scanf("%d", &info[posicao].cep);
}else{
printf("Nome ja existente \n");

}
}

int livre(void) {
int i;
for( i=0; info[i].nome[0] && i< MAX; i++);
if( i == MAX ) return -1;
return i;
}

void apaga(void) {
int posicao;
printf("Número do Registro: ");
scanf("%d",&posicao);
if(posicao >=0 && posicao < MAX)
info[posicao].nome[0]='\0';
}

void imprime(void){
int i;
for( i=0; i < MAX; i++)
if(info[i].nome[0] != '\0')
{
printf("-- Registro %d:\n", i);
printf("\t Nome: %s", info[i].nome);
printf("\t Rua: %s", info[i].rua);
printf("\t Cidade: %s", info[i].cidade);
printf("\t Estado: %s\n", info[i].estado);
printf("\t CEP: %lu\n", info[i].cep);
}
}

int BuscaPorNome(char *nome){
int i=0;
while(i<MAX){
    if (strcmp(nome,info[i].nome)==0){
        return i;
    }
    i++;
}
return -1;


}

void ApagaPorNome(void){
    char nome[31],c;
    int posicao;
    printf(" Digite o nome para ser removido \n");
    ler_string(nome,30);
    posicao=BuscaPorNome(nome);
    if(posicao>=0){
            do{
           printf("voce deseja exclui o registro de '%s' ? (s/n)\n",nome);
                     c=getchar() ;
                    }while(c!='s' && c!='n');
                    if(c=='s'){
        info[posicao].nome[0]='\0';
                    }
    }else{
    printf("O resgistro de  '%s' nao foi encontrado!\n",nome);
    }
}

void ImprimePorNome(void){
 char nome[31],c;
    int posicao;
    printf(" Digite o nome para ser localizado \n");
    ler_string(nome,30);
    posicao=BuscaPorNome(nome);
    if(posicao>=0){
printf("-- Registro %d:\n", posicao);
printf("\t Nome: %s", info[posicao].nome);
printf("\t Rua: %s", info[posicao].rua);
printf("\t Cidade: %s", info[posicao].cidade);
printf("\t Estado: %s\n", info[posicao].estado);
printf("\t CEP: %lu\n", info[posicao].cep);
    }else{
    printf("nome nao localizado\n");
    }

}

int ProcuraPorNomes(char *str,int *posicoes){
int i,j=0;
for(i=0; i<MAX;i++){
    if(strstr(info[i].nome,str)){
    posicoes[j]=i;
        j++;
    }
  }
  return j;
}

void ImprimeListaDeNomes(void){
int posicoes[MAX],TAM,i;
char nome [31];
printf("digite o nome a ser procurado  ");
ler_string(nome,30);
TAM=ProcuraPorNomes(nome,posicoes);
if(TAM>0){
for(i=0;i<TAM;i++){
    printf("registro:%d - %s\n",posicoes[i],info[posicoes[i]].nome);
}

}else{
printf("nenhum resgistro encontrado");
}
}

int OrdenaPorNome(int *posicoes){
int i,j,p=0,temp;
for(i=0;i<MAX;i++){
    if(info[i].nome[0]){
        posicoes[p]=i;
        p++;
    }
}
for(i=0;i<p;i++){
    for(j=i+1;j<p;j++){
        if(strcmp(info[posicoes[i]].nome,info[posicoes[j]].nome)>0){
           temp=posicoes[i];
           posicoes[i]=posicoes[j];
           posicoes[j]=temp;
        }
    }

}
return p;
}
void ImprimeOrdenaPorNome(void){
int posicoes[MAX],TAM,i;
TAM=OrdenaPorNome(posicoes);
for(i=0;i<TAM;i++){
    printf("%3d :%s (%d)\n",i,info[posicoes[i]].nome,posicoes[i]);

}

}

void GravarDadosBin(char *nome_arq){
FILE *arq;
int i;
if((arq=fopen(nome_arq,"wb"))== NULL){
    printf("ERROR: O Arquivo %s não ser aberto!",nome_arq);
    return;
}
for(i=0;i<MAX;i++){
if(info[i].nome[0]!='\0'){
    fwrite(&info[i],sizeof(struct end),1,arq);
}

}

fclose(arq);
}


void lerDadoBin(char *nome_arq){
FILE *arq;
int i=0;
if((arq=fopen(nome_arq,"rb"))==NULL){
    printf("ERROR: O Arquivo %s não foi encontrado!",nome_arq);
    return;
}
while(!feof(arq)&&i<MAX){
    fread(&info[i],sizeof(struct end),1,arq);
    i++;
}
for(;i<MAX;i++){
    info[i].nome[0]='\0';
}
fclose(arq);
}
void GravarDadosTxT(char *nome_arq){
    FILE *arq;
int i;
if((arq=fopen(nome_arq,"w"))== NULL){
    printf("ERROR: O Arquivo %s não ser aberto!",nome_arq);
    return;
}
for(i=0;i<MAX;i++){
if(info[i].nome[0]!='\0'){
    fwrite(&info[i],sizeof(struct end),1,arq);
}

}

fclose(arq);
}



void lerDadotxt(char *nome_aqr){
FILE *arq;
int i=0;
if((arq=fopen(nome_aqr,"r"))==NULL){
   printf("ERROR: O Arquivo %s não foi encontrado!",nome_aqr);
    return;
}
while(!feof(arq)&&i<MAX){
    fgets(info[i].nome,30,arq);
    if(info[i].nome[strlen(info[i].nome)-1]=='\n'){
        info[i].nome[strlen(info[i].nome)-1]='\0';
    }
    if(info[i].rua[strlen(info[i].rua)-1]=='\n'){
        info[i].rua[strlen(info[i].rua)-1]='\0';
    }
   if(info[i].cidade[strlen(info[i].cidade)-1]=='\n'){
        info[i].cidade[strlen(info[i].cidade)-1]='\0';
    }
    if(info[i].estado[strlen(info[i].estado)-1]=='\n'){
        info[i].estado[strlen(info[i].estado)-1]='\0';
    }
    fscanf(arq,"%lu",&info[i].cep);
    i++;
}
for(;i<MAX;i++){
    info[i].nome[0]='\0';
}
fclose(arq);
}

