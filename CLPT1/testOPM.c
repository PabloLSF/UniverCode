#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>




  int main(int argc,char *argv[])
  {
      //printf("test\n");
      #pragma omp parallel num_threads(4)
{
    printf("test\n");
   //int id = omp_get_thread_num();
  //int nt = omp_get_num_threads();
    //printf("eu sou %d de %d\n",id,nt);

}
   // printf("test\n");


  return 0;
  }
