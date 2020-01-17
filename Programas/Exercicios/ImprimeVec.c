#include <stdio.h>
void insertion(int *v,int n);
void imprimevetor(int *v,int n);
int main(){
int v[8000], n,c;

  printf("Digite o numero de elementos\n");
  scanf("%d", &n);



  for (c = 0; c < n; c++){
    v[c]=  rand() % 8000;
  }
  imprimevetor(v,n);
  insertion(v,n);
  imprimevetor(v,n);
}



void imprimevetor(int *v,int n){
int c;

for (c = 0; c <n ; c++){
    printf(" %d ",v[c]);
  }
   printf(" \n");
}
void insertion(int *v,int n){
  int   i, d, t;



  for (i = 1 ; i <= n - 1; i++) {
    d = i;

    while ( d > 0 && v[d] < v[d-1]) {
      t          = v[d];
      v[d]   = v[d-1];
      v[d-1] = t;

      d--;
    }
  }
}
