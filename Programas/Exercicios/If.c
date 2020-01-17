#include <stdio.h>
int main (void){
int number = 0;
printf("\n Enter an interger between 1 and 10: ");
scanf ("%d"  ,&number);
if(number >5)
printf ("you enterd %d which is greater than 5\n", number);
if (number <6)
printf ("you enter %d which is less than 6\n",number);
return 0;
}
