#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct data {

int dia;

int mes;

int ano;

};


int main (){

struct data x;

x.dia=10;
x.mes=1;
x.ano=1990;

printf("dia %d mes %d ano %d",x.dia ,x.mes,x.ano);
return 0;
}
