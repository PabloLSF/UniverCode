#include <stdio.h>
#include <stdlib.h>
#include "pls.h"
#define TAM 5

struct pilha {
       int Np[TAM];
       int topo;
};
void inicializa(struct pilha *p){
     p -> topo = -1;
}
void imprimePilha(struct pilha *p1,struct pilha *p2,struct pilha *p3) {
    int i;
     for (i=p1->topo;i>=0;i--){
            printf("|%d| ",p1->Np[i]);
  if(p2->Np[i]<5 && p2->Np[i]>0 ){
         printf("|%d| ",p2->Np[i]);
  }else{
  printf("| | ");
  }
  if(p3->Np[i]<5 && p3->Np[i]>0){
         printf("|%d| ",p3->Np[i]);
}else{
  printf("| | ");
  }
          printf("\n");
        }



}
void empilha (struct pilha *p, int elemento) {
    p -> topo++;
     p -> Np[p -> topo] = elemento;
}
void desempilha (struct pilha *p) {
    p->topo--;
}
int retornaTopo(struct pilha *p) {
    int i=0;
    i=p->topo;
    return p->Np[i];
}
int tamanho(struct pilha *p) {
    return p->topo+1;
}
int menu(void) {
int c=0;
do {
printf("-- MENU:\n");
printf("\t 1. moverElemento \n");
printf("\t 2.  imprimir a pilha\n");
printf("\t 3.  Sair\n");
printf("-- Digite sua escolha: ");
scanf("%d", &c);
} while(c<=0 || c>3);
getchar();
return c;
}
int menuMove(void) {
int c=0;
do {
printf("-- MENU Mover:\n");
printf("\t 1. Mover Torre 1 para 2 \n");
printf("\t 2. Mover Torre 1 para 3\n");
printf("\t 3. Mover Torre 2 para 1\n");
printf("\t 4. Mover Torre 2 para 3\n");
printf("\t 5. Mover Torre 3 para 1\n");
printf("\t 6. Mover Torre 3 para 2\n");
printf("-- Digite sua escolha: ");
scanf("%d", &c);
} while(c<=0 || c>6);
getchar();
return c;
}
void moverElemento(struct pilha *p1,struct pilha *p2){
int numTop;

numTop=retornaTopo(p1);
desempilha(p1);
empilha(p1,0);
desempilha(p1);
if(retornaTopo(p2)>5 || p2->topo==-1 || retornaTopo(p2)==0){
 empilha(p2,numTop);
}else
 if(numTop < retornaTopo(p2)){
empilha(p2,numTop);


}else{
     printf("Movimento invalido \n");
    empilha(p1,numTop);

     }

}

