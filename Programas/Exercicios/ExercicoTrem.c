#include <stdio.h>
#include <time.h>
int main()
{
  int Trem[8000], n, c, d, swap,troca=0;
 clock_t stop ,start = clock();
double elapsed ;
  printf("Digite o numero de vagoes\n");
  scanf("%d", &n);



  for (c = 0; c < n; c++){
    Trem[c]=  rand() % 8000;
  }
  printf("os vagoes com os numeros gerados foram\n");
  for (c = 0; c < n; c++){
    printf("-|%d|-",Trem[c]);
  }
  printf("\n");
  printf("\n");

  for (c = 0 ; c < ( n - 1 ); c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {


      if (Trem[d] > Trem[d+1])
      {

          troca=troca+1;
        swap       = Trem[d];
        Trem[d]   = Trem[d+1];
        Trem[d+1] = swap;

      }
    }
  }

if(troca==0){
    printf("Melhor caso\n");
     stop = clock();
     elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
   printf("Tempo  de execucao em ms : %f", elapsed);
  printf("\n");
}else if (troca<c){
  stop = clock();
     elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo  de execucao em ms : %f", elapsed);
      printf("\n");
    }else{

printf("Pior  caso\n");
     stop = clock();
    elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo  de execucao em ms : %f", elapsed);
  printf("\n");
}
  printf("\n");
  for ( c = 0 ; c < n ; c++ )
    printf("-|%d|-",Trem[c]);

     printf("Numero de trocas %d",troca);


     printf("\n");
 system("PAUSE");
  return 0;
}
