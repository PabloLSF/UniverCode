#include


void for_sub_(int *, double *, double *, int *);
int main()
{
int i = 1, ny = 3;
double pi = 3.14159;
double y[] = {1.1, 2.2, 3.3};
// pular uma linha para melhor visualizacao

printf("_____________________________________________\n");
printf(" C chamando subrotina em fortran, passando\n");
printf(" i = %d, pi = %g\n", i, pi);
printf(" y[] = %g, %g, %g\n", y[0], y[1], y[2]);
printf("_____________________________________________");
//pular uma linha para melhor visualizacao

for_sub_(&i, &pi, y, &ny);
return 0;
}
