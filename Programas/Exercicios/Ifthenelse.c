#include <stdio.h>
int main (void){
const double u = 3.50;
int q = 0;
double total= 0.0;
printf("numero de parcelas");
scanf("%d", &q);
if (q>10)
total=q*u*0.95;
else
total=q*u;
printf("o preco para %d é $%.2f\n",q ,total);
return 0;
}
