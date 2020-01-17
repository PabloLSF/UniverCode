#include <stdio.h>

#include "LocadoraFunc.c"


int main(void) {
int escolha;



for( ; ; ) {

escolha = menu();
switch(escolha) {
case 1: locar();
break;
case 2: entrega();
break;
case 3: Buscacod();
break;
case 4: ImprimePorNome();
break;
case 5: BuscaAno();
break;
case 6: ImprimePorGenero();
break;
case 7:impress();
break;
case 8:  exit(0);
break;
}
}
}

