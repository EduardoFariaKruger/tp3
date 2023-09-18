/* Arquivo MAIN que usa o TAD racionais */

/* coloque seus includes aqui */
#include "racionais.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX = 100

/* coloque funcoes desejadas aqui. 
 * Exemplo: ordenar, eliminar invalidos... */


void criar_vetor(struct racional **vetor, int tam)
{   
    long int num;
    long int den;
    for (int i=0; i <= tam-1; i++)
    {
        scanf("%ld", &num);
        scanf("%ld", &den);
        vetor[i] = cria_r(num, den);
    }
}

/*imprime os elementos de um vetor de racionais*/
void imprimir_vetor(struct racional **vetor, int tam)
{
    for (int i=0; i <= tam-1; i++)
    {
        imprime_r(vetor[i]);
    }
    printf("\n");
}

/*ordena um vetor de racionais do menor para o maior*/
void ordenar_vetor(struct racional **vetor, int tam)
{
{
    struct racional *aux;
    for (int i = 0; i < tam; i++)
    {
        int menor = i;
        for (int j = i + 1; j < tam; j++)
        {
            if (compara_r(vetor[j], vetor[menor]) == -1)
            {
                menor = j;
            }
        }
        aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;
    }
}
}

/*identifica e elimina todos os números racionais inválidos dentro do vetor, esse algoritmo é quadrático, porém ele funciona para qualquer instância desse problema*/
void elimina_invalido(struct racional **vetor, int *tam)
{
    for (int i = 0; i < *tam; i++)
    {
        if (!valido_r(vetor[i]))
        {
            vetor[i] = vetor[*tam - 1];
            *tam = (*tam) - 1;
            i--;
            destroi_r(vetor[*tam-1]);
        }
    }
}

void insertionSort(struct racional **vetor, int n) {
    int i, j;
    struct racional *chave;
    for (i = 1; i < n; i++) {
        chave = vetor[i];
        j = i - 1;
        while (j >= 0 && compara_r(vetor[j], chave) == 1) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

struct racional *soma_vetor(struct racional **vetor, int tam)
{
    struct racional *soma = cria_r(0, 1);
    for (int i = 0; i < tam; i++)
    {
        soma_r(soma, vetor[i], soma);
    }
    return soma;
}

int main (){
    /* vetor de ponteiros para racionais */
    struct racional **vetorPointers;
    struct racional *soma;
    int n, i;

    scanf("%d", &n);

    vetorPointers = (struct racional **) malloc(n*(sizeof(struct racional *)));

    


    criar_vetor(vetorPointers, n);

    imprimir_vetor(vetorPointers, n);

    elimina_invalido(vetorPointers, &n);

    imprimir_vetor(vetorPointers, n); 

    ordenar_vetor(vetorPointers, n);   

    imprimir_vetor(vetorPointers, n);

    soma = soma_vetor(vetorPointers, n);
    printf("a soma de todos os elementos eh: ");
    imprime_r(soma);
    printf("\n");

    for (i = 0; i < n; i++)
    {
        destroi_r(vetorPointers[i]);
    }

    free(vetorPointers);

    return 0;
}
