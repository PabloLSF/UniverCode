#include <stdio.h>
#include <time.h>
int main()
{
    int v[1000],c,n;
    clock_t stop ,start = clock();
double elapsed ;
  printf("Digite o numero de vagoes\n");
  scanf("%d", &n);



  for (c = 0; c < n; c++){
    v[c]=  rand() % 8000;
  }
  imprimevetor(v,n);
  insertion(v,n);
 imprimevetor(v,n);
}
