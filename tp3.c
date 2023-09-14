/* Arquivo MAIN que usa o TAD racionais */

/* coloque seus includes aqui */
#include "racionais.h"
#include <stdio.h>
#include <stdlib.h>


/* coloque funcoes desejadas aqui. 
 * Exemplo: ordenar, eliminar invalidos... */


void criar_vetor(struct racional **vetor[], int tam)
{   
    long int num;
    long int den;
    for (int i=0; i <= tam-1; i++)
    {
        scanf("%ld", &num);
        scanf("%ld", &den);
        *vetor[i] = cria_r(num, den);
    }
}

/*imprime os elementos de um vetor de racionais*/
void imprimir_vetor(struct racional * vetor[], int tam)
{
    for (int i=0; i <= tam-1; i++)
    {
        imprime_r(vetor[i]);
    }
    printf("\n");
}

/*ordena um vetor de racionais do menor para o maior*/
void ordenar_vetor(struct racional *vetor[], int tam)
{

}

/*identifica e elimina todos os números racionais inválidos dentro do vetor, esse algoritmo é quadrático, porém ele funciona para qualquer instância desse problema*/
void elimina_invalido(struct racional vetor[], int *tam)
{

}

int main (){
    /* vetor de ponteiros para racionais */
    struct racional * vetorPointers[10];

    struct racional u ;
    u.num = 1;
    u.den = 9;

    vetorPointers[0] = &u;

    imprimir_vetor(vetorPointers, 1);

    return 0;
}
