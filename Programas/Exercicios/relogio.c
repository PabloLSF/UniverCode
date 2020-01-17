
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ESC 27
int main(void)
{
time_t tempo;
struct tm *data;
int h,m,s;
char tecla;
do {
 time(&tempo);
 printf("Data em segundos: %ld\n", (long) tempo);
 data = localtime(&tempo);
 printf("Data de Hoje\n");
 printf(" Dia: %d\n", data->tm_mday);
 printf(" Mes: %d\n", data->tm_mon+1);
 printf(" Ano: %d\n", data->tm_year+1900);
 printf("Horario Atual:\n");
 h = data->tm_hour;
 m = data->tm_min;
 s = data->tm_sec;
 printf(" Horas: %d\n",h);
 printf(" Minutos: %d\n",m);
 printf(" Segundos: %d\n",s);
 printf("[ESC] - Abandona - [ENTER] - Atualiza: ");
 tecla = getchar();
 } while (tecla != ESC);
}
