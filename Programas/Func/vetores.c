#include <stdio.h>
#include <stdlib.h>



int main (void){
  
 int c,i=0,ind,cas,t,r;
 
 
   printf("de  o numero de casa  para  o vetor \n");
   scanf("%d" ,&c);
 int v[c];
  
 for (i=0;i<c;i++) {
   
   printf("adicione um valor \n");
   scanf("%d" ,&v[i]);
   }
  do{
 printf("diguite 1 para escolher o lugar do vetor de ou 2 para  escrever o vetor inteiro ou 3  para um valor  aleatorio \n " ); 
scanf("%d", &cas);


 switch (cas){
   case 1:
   
    
 
   scanf("%d" ,&ind);
  
    
  printf("local  no vetor %d  numero %d /n",ind ,v[ind]);
  break;

 case 2:
    for (i=0;i<=c;i++){
   printf("local %d numero %d \n",i,v[i]);
   
   }
   break;
  case 3:
   r= rand() % c;
    printf("local %d numero %d \n",r,v[r]);
  break;

}
printf("digite 1 para para sair");
scanf("%d" ,&ind);
}while (cas==1);

return 0;
}
