#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <math.h>
/*
 * File:   main.c
 * Author: Pablo sanches
 *
 * Created on 11 de Junho de 2019, 11:29
 * Versão 0.6 date 13/06/2019
 */
/*


gcc -o nomeDoarquivo -fopenmp nomeDoarquivo.c
export OMP_NUM_THREADS=2
 ./nomeDoarquivo
 */


void paralelo(int n, int m, int p);
int equad(int tam, int grau);
int fib(int n);
int mult(int valor, int cont);
int menu(void);
int pot(int valor, int cont);
int squad(int n);
int cub(int n);
int divalor(int num);

int main(int argc, char** argv) {
    int escolha;
    int valor1, valor2;
    int result;
    int n, m, p, i, tag;
    for (;;) {
        escolha = menu();
        switch (escolha) {
            case 1:
                printf("-- Valor para aplicar Raiz quadrada: \n");
                scanf("%d", &valor1);
                result = squad(valor1);
                printf("Resultado: %d \n", result);
                break;
            case 2:
                printf("-- Valor de A e o valor de B para serem multiplicados: \n");
                scanf("%d", &valor1);
                scanf("%d", &valor2);
                result = mult(valor1, valor2);
                printf("Resultado: %d \n", result);
                break;
            case 3:
                printf("-- Valor para aplicar Raiz Cubica: \n");
                scanf("%d", &valor1);
                result = cub(valor1);
                printf("Resultado: %d \n", result);
                break;
            case 4:

                tag = 0;
                printf("Diga o tamanho de um vetor\n");
                scanf("%d", &n);
                do {
                    printf("Diga o um valor de módulo Entre 10 a 40\n");
                    scanf("%d", &m);
                    if (m > 9 && m < 41) {
                        tag = 1;
                    } else {
                        printf(" valor de módulo esta fora das especificações\n");
                    }
                } while (tag == 0);

                printf("Diga o número de threads do time de execução\n");
                scanf("%d", &p);
                paralelo(n, m, p);

                break;
            case 5:
                printf("-- Fução não implementarda \n");

                break;
            case 6:
                printf("-- Valor de A e o valor de B para ser A^B \n");
                scanf("%d", &valor1);
                scanf("%d", &valor2);
                result = pot(valor1, valor2);
                printf("Resultado: %d \n", result);
                printf("-- Fução não implementarda \n");

                break;
            case 7:
                exit(0);
                break;
        }
    }
}

// multiplicação

int mult(int valor, int cont) {
    int novoCont = cont;
    int j = 0;
    int stack = 0;
    int teste;
    int i;
    int imp = 0;
    int mult = 0;
    int p;
    teste = divalor(novoCont);
    if (teste != 0) {
        do {
            teste = divalor(novoCont);
            if (teste == 1) {
                novoCont = novoCont / 2;
            }
            if (teste == 2) {
                novoCont = novoCont / 2;
                stack = stack + pow(2, j);
            }
            j++;
        } while (teste != 0);
    }
    if (cont % 2 == 0) {
        p = cont / 2;
    } else {
        imp = 1;
        p = 1 + (cont / 2);
    }
    int aux;

    if (j == 0) {
        aux = 1;
    } else {
        aux = pow(2, j - 1);
    }
    int somas[p];
    int vet[aux];
    int total = 0;
    printf("Auxiliar %d\n", aux);
    for (i = 0; i < aux; i++) {
        vet[i] = novoCont;
        printf("Valor %d\n", novoCont);
    }
    for (i = 0; i < aux; i++) {
        total = total + novoCont;
    }
    total + stack;
    printf("total %d\n", total);

    if (valor == 0 || cont == 0) {
        return 0;
    } else if (valor == 1 || cont == 1) {
        if (valor < cont) {
            return cont;
        } else {
            return valor;
        }
    } else {

#pragma omp parallel num_threads(p)

        {
#pragma omp for
            for (i = 0; i < cont; i++) {

                somas[omp_get_thread_num()] = valor + valor;

                // printf("imp soma %d, thread %d \n",somas[omp_get_thread_num()],omp_get_thread_num());
            }
        }



        if (imp == 1) {
            somas[p - 1] = valor;
            for (i = 0; i < p; i++) {
                mult = mult + somas[i];
            }
        } else {
            for (i = 0; i < p; i++) {
                mult = mult + somas[i];
            }
        }
        return mult;

    }
}
// função fib

int fib(int n) {
    int i, x = 1, y = 1, soma;
    for (i = 3; i <= n; i = i + 1) {
        soma = x + y;
        x = y;
        y = soma;
    }
    return y;
}

int squad(int n) {
    return mult(n, n);

}

int cub(int n) {
    int cub = 0;
    cub = mult(n, n);
    cub = mult(cub, n);
    return cub;
}

int equad(int tam, int grau) {
    //x gru + xgrau-1 + (x + val)*(val+)
    int val[tam];
    int i;
    for (i = 0; i < tam; i++) {
        val[i] = rand() % 100;
    }



}

int menu(void) {
    int c = 0;
    do {
        printf("-- MENU:\n");
        printf("-- Escolha sua operação:\n");
        printf("\t 1. Raiz quadrada\n");
        printf("\t 2. Multiplicação\n");
        printf("\t 3. Raiz Cubica\n");
        printf("\t 4. Fibonate\n");
        printf("\t 5. Equações\n");
        printf("\t 6. Potencia\n");
        printf("\t 7. Sair\n");
        printf("-- Digite sua escolha: ");
        scanf("%d", &c);
    } while (c <= 0 || c > 7);
    getchar();
    return c;
}

void paralelo(int n, int m, int p) {
    int i;
    int vet[p];

    printf("Testes com OpenMP\n");
    //inicio do paralelismo  com p threads
#pragma omp parallel num_threads(p)
    {
        // medidor de tempo responsavel para ver o tempo de execução do programa
        clock_t stop, start = clock();
        double elapsed;

        printf("\n");

        //executando o codigo em paralelo #pragma omp for Realiza a divizões nas threads
#pragma omp for
        for (i = 0; i < n; i++) {
            vet[i] = fib(i % m);
            //printf("-%d-",vet[i]);
        }
        printf("\n");
        //sotp  diz o tempo gasto no processo
        stop = clock();
        elapsed = (double) (stop - start) * 1000.0 / CLOCKS_PER_SEC;
        printf("Tempo  de execucao em ms : %f", elapsed);
        printf("\n");
    }
}

int pot(int valor, int cont) {
    int val;
    int i;
    int imp = 0;
    int result = valor;
    int p;
    int j = 0;
    if (cont % 2 == 0) {
        p = cont / 2;
    } else {
        imp = 1;
        p = 1 + (cont / 2);
    }
    if (cont == 0) {
        return 1;
    } else if (cont == 1) {
        return valor;
    } else {
        if (imp == 1) {
            for (i = 1; i < cont - 1; i++) {
                result = mult(result, valor);
            }
            result = mult(result, valor);
        } else {
            for (i = 1; i < cont; i++) {
                result = mult(result, valor);
            }
        }
        return result;
    }
}

int divalor(int num) {

    if (num < 9) {
        return 0;
    } else {
        if (num % 2 == 0) {
            return 1;
        } else {
            return 2;
        }
    }


}