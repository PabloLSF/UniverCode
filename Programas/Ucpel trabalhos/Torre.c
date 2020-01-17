#include <stdio.h>
#include <stdlib.h>
#define TAM 10

struct pilha {
       int vp[TAM];
       int topo;
};
//antes do main, DEFINIR ESCOPO das funções do programa
void inicializa(struct pilha *p);
void insere(struct pilha *p, int elemento);
void imprimir(struct pilha *p);
void remover(struct pilha *p);
int menu(void);
int main(int argc, char *argv[]){
     struct pilha p1;
     int n,idade;
     inicializa(&p1);


            for( ; ; ) {
           n = menu();
     switch(n)
     {
              case 1:
                   printf("Digite sua idade:");
                   scanf("%d",&idade);
                   insere(&p1,idade);
                   break;
              case 2:
                   remover(&p1);
                   break;
              case 3:
                   system("cls");
                   printf("Pilha 1:\n");
                   imprimir(&p1);
                   system ("pause");
                   break;
              case 4://imprime o elemnto do topo da pilha
                   printf("\n%d\n\n",p1.vp[p1.topo]);
                   system("pause");
                   break;
              case 5:
                   return 0;
                   break;
                   }
            }



  system("PAUSE");
  return 0;
}

void inicializa(struct pilha *p){//inicializa a pilha com -1
     p -> topo = -1; // p.topo 'testar'
}
void insere(struct pilha *p, int elemento){//insrete um elemnto na pilha
     p -> topo++;
     p -> vp[p -> topo] = elemento;
     }
void imprimir(struct pilha *p){//imrime todos os elemntos da pilha
     int i;
     for (i=p->topo;i>=0;i--){
         printf("%d\n",p->vp[i]);
         }
}
void remover(struct pilha *p){//remove o elemnto do topo da pilha
     p -> topo --; // p.topo 'testar'
}
int menu(void) {
int c=0;
do {
printf("-- MENU:\n");
printf("\t 1. inicializa \n");
printf("\t 2. insere \n");
printf("\t 3. imprimir\n");
printf("\t 4. remover\n");
printf("\t 5. Sair \n");
printf("-- Digite sua escolha: ");
scanf("%d", &c);
} while(c<=0 || c>5);
getchar();
return c;
}
