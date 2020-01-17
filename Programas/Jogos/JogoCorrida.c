#include <stdio.h>
#include "jogas.h"
#include "jogas.c"

struct jogador {
int cod;
char nome[50];
};
 struct Tabuleiro {
 int Tab[10][10];

 };

int main (void){
int mover=1;

int jooo=jogadas(&mover);
printf("movido %d",&jooo);

return 0;

}
