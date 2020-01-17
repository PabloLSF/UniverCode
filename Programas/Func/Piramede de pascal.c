#include <stdio.h>

int main (){
int p[100][100], col,i,j;
char s=" ";

float es=0, div=0;
for (i=0;i<100;i++){
    for (j=0;j<100;j++){
        p[i][j]= 0;
    }
}
printf("digite um numero de colunas   ");
scanf ("%d",&col);
for (i=0;i<col;i++){
    for (j=0;j<100;j++){
        if(i==j){
            p[i][j]=1;
}else if(i<j){
    p[i][j] = 0;
}else if(j==0){
    p[i][j]=1;
}else{
  p[i][j] =  p[i-1][j] + p[i-1][j-1];
}
    }
}

for (i=0;i<col;i++){
       do{

        printf("%c",s);
        es=es+0.5;
        div=(col-i)/2;
       } while( es <= div);
    for (j=0;j<100;j++){
            if(p[i][j]!=0){

                printf(" %d ",p[i][j]);
            }

    }
    printf("\n");
    es=0;
}
return 0;
}
