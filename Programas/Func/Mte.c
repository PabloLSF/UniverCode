#include <stdio.h>
#include <math.h>

int main (void){

int f,i,cont,ac,n;
n=0;

printf("digite um numero para ser fatoriado \n");

 scanf ("%d",&f);
 cont=f-1;
ac=1;
for (i=f;i>1;i--){
 
 n++;
  ac=ac*i;
  

 }
  printf("numero de  operações %d numero total %d \n",n,ac);
}
