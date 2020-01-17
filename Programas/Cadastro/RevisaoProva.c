#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RevisaoProvaF.c"


int main(void) {
int escolha;
cria_lista();
for( ; ; ) {
escolha = menu();
switch(escolha) {
case 1: insere();
break;
case 2: apaga();
break;
case 3: imprime();
break;
case 4: ApagaPorNome();
break;
case 5: ImprimePorNome();
break;
case 6: ImprimeListaDeNomes();
break;
case 7: ImprimeOrdenaPorNome();
break;
case 8: exit(0);
break;
}
}
}
