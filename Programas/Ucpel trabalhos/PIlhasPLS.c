#include <stdio.h>
#include "plsFunc.c"



int main(int argc, char *argv[]){
struct pilha p1, p2, p3;
     int n,elemento,i,j,f;
inicializa(&p1);
inicializa(&p2);
inicializa(&p3);
  j=5;
  for(i=0 ;i<5 ;i++) {
       empilha(&p1,j);
       j--;
  }


            for( ; ; ) {
           n = menu();
     switch(n)
     {
              case 1:
                  system("cls");
                  f=menuMove();
                  switch(f){
                  case 1:
                      moverElemento(&p1,&p2);
                   break;
                    case 2:
                        moverElemento(&p1,&p3);
                   break;
                    case 3:
                        moverElemento(&p2,&p1);
                   break;
                    case 4:
                        moverElemento(&p2,&p3);
                   break;
                    case 5:
                        moverElemento(&p3,&p1);
                   break;
                    case 6:
                        moverElemento(&p3,&p2);
                   break;
                  }
                    break;
              case 2:
                system("cls");
                  imprimePilha(&p1,&p2,&p3);
                   break;
              case 3:
                   return 0;
                   break;
                   }
            }



  system("PAUSE");
  return 0;
}
