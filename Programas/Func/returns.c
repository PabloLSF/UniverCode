#include <stdio.h>
int pot(int n, int e);
int total=0;

void main (void){
int t = 10;

printf("%d %d %d ",t,total,pot(t,2));

}
int pot(int n, int e){
for(;e>1;e--){

total=total*n;
return(total);
}
}
