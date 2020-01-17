/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Mariz.c
 * Author: Pablo
 *
 * Created on 12 de Novembro de 2018, 18:34
 */

#include <stdio.h>

#include <stdlib.h>




int **matriz(int n);
int **matriZero(int n);
int **multMatriz(int **m, int**n, int t);
int main(int argc, char** argv) {
int i,j,n;
printf("diaga o tanmanho da matriz nxn: ");
scanf("%d",&n);
 int **m=matriz(n);
 int **v=matriz(n);
 int **p=multMatriz(m,v,n);
for (i = 0; i < n; i++){

        printf("\n");
          for (j = 0; j < n; j++){

printf("|%d|",m[i][j]);
          }
}
for (i = 0; i < n; i++){

        printf("\n");
          for (j = 0; j < n; j++){

printf("|%d|",v[i][j]);
          }
}

for (i = 0; i < n; i++){

        printf("\n");
          for (j = 0; j < n; j++){

printf("|%d|",p[i][j]);
          }
}

    return (EXIT_SUCCESS);
}



int **matriz(int n){
int i,j,r;

int **m = (int**)malloc(n * sizeof(int*));
 for (i = 0; i < n; i++){
       m[i] = (int*) malloc(n * sizeof(int));
       for (j = 0; j < n; j++){

            m[i][j] = 0;
      }
 }
 for (i = 0; i < n; i++){

        printf("\n");
          for (j = 0; j < n; j++){
                r=smat(50,61);
              m[i][j] =r;

          }
}
return m;
}
int **matriZero(int n){

int i,j,r;

int **m = (int**)malloc(n * sizeof(int*));
 for (i = 0; i < n; i++){
       m[i] = (int*) malloc(n * sizeof(int));
       for (j = 0; j < n; j++){

            m[i][j] = 0;
      }
 }
 for (i = 0; i < n; i++){

        printf("\n");
          for (j = 0; j < n; j++){

              m[i][j] =0;

          }

}
return m;
}
int **multMatriz(int **m, int**n, int t){
int **p=matriZero(t);
int i,k1,k2,temp;
  for(k1=0;k1<t;k1++)
    {
        for(k2=0;k2<t;k2++)
        {
            temp=0;
            for(i=0;i<t;i++)
            {
                temp=temp+(m[k1][i])*(n[i][k2]);
            }
            p[k1][k2]=temp;
        }
    }


          return p;
}




