#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
/*
Integrantes do grupo  Tamires, Taison e Pablo
Em grupo de até 3 estudantes
Entrega: 12/dez
Especificação:
Em OpenMP, implementar um programa que receba três entradas: N, M e P, onde:
N representa o tamanho de um vetor
M um valor de módulo
P o número de threads do time de execução
O programa deve preencher cada posição i do vetor com o valor do Fibonacci de i % M (i módulo M).
Observe que o valor M deve ser entre 10 e 40.
Deve ser entregue o programa fonte comentado e uma análise de desempenho que apresente a relação entre tempo de execução,
e os valores N, M e P informados
*/
int fib(int n);
void paralelo(int n, int m,int p);
void normal (int n, int m,int p);
   int main(int argc,char *argv[])
  {

//declaração de vareaveis e entradas
    int n,m,p,i,tag;
    tag=0;
 printf("Diga o tamanho de um vetor\n");
  scanf("%d", &n);
  do{
    printf("Diga o um valor de módulo Entre 10 a 40\n");
  scanf("%d", &m);
  if(m>9 && m<41){
    tag=1;
  }else{
      printf(" valor de módulo esta fora das especificações\n");
  }
  }while(tag==0);

   printf("Diga o número de threads do time de execução\n");
  scanf("%d", &p);
paralelo(n,m,p);
normal(n,m,p);

    return 0;
   }



void paralelo(int n, int m,int p){
int i;
  int *vet;
   vet = (int *) malloc(n* sizeof(int));
printf("Testes com OpenMP\n");
//inicio do paralelismo  com p threads
#pragma omp parallel num_threads(p)
{
    // medidor de tempo responsavel para ver o tempo de execução do programa
    clock_t stop ,start = clock();
   double elapsed ;

printf("ola\n");

//executando o codigo em paralelo #pragma omp for Realiza a divizões nas threads
#pragma omp for
      for(i=0;i<n;i++){
        vet[i]=fib(i%m);
        printf("-%d-",vet[i]);
      }
      printf("\n");
      //sotp  diz o tempo gasto no processo
   stop = clock();
     elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo  de execucao em ms : %f", elapsed);
    printf("\n");
}
}

void normal (int n, int m,int p){
int i;
  int *vet;
   vet = (int *) malloc(n* sizeof(int));

// o mesmo procedimento sendo realizado sem usar o paralelismo
printf("Testes sem OpenMP\n");
 clock_t stop ,start = clock();
double elapsed ;
 for(i=0;i<n;i++){
        vet[i]=fib(i%m);
        printf("-%d-",vet[i]);
      }
      printf("\n");
stop = clock();
     elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo  de execucao em ms : %f", elapsed);
    printf("\n");

}









   int fib(int n)
    {
      int i, x = 1, y = 1, soma;
      for (i = 3; i <= n; i = i + 1)
      {
       soma = x + y;
        x = y;
       y = soma;
     }
     return y;
   }

