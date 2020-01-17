#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


struct Aluno {
int cod;
char nome[21];
char sobrenome[21];


};


struct AlunoNotas {

 float notaInicio;
 float notaFim;
 float media;


};


int main(){

struct Aluno NovoAuno[2];
struct AlunoNotas NovoAlunoNota[2];
int i;


for(i=0;i<2;i++){
    printf("incira  os dados  pessoais  do aluno \n ");
    printf(" nome e  sobrenome: \n");
   scanf(" %s",&NovoAuno[i].nome);
   scanf(" %s",&NovoAuno[i].sobrenome);



    printf(" incira codico e as notas iniciais e finais do aluno \n" );
    printf("incira codigo : \n");
    scanf("%d",&NovoAuno[i].cod);

    printf("incira as notas iniciais  e finais \n");
    scanf("%f",&NovoAlunoNota[i].notaInicio);
    scanf("%f",&NovoAlunoNota[i].notaFim);


    NovoAlunoNota[i].media=  ( NovoAlunoNota[i].notaFim + NovoAlunoNota[i].notaInicio)/2;
}
printf("\n");
printf("\n");
printf("--------------------------------------\n");

for(i=0;i<2;i++){
       printf(" codigo: %d nome: %s  %s \n",NovoAuno[i].cod, NovoAuno[i].nome,NovoAuno[i].sobrenome);
       printf("Nota inicial %0.2f  Nota Final %0.2f  Media %0.2f \n",NovoAlunoNota[i].notaInicio,NovoAlunoNota[i].notaFim,NovoAlunoNota[i].media);
}
printf("--------------------------------------\n");


return 0;


}
