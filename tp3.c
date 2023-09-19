/* Arquivo MAIN que usa o TAD racionais */

/* coloque seus includes aqui */
#include "racionais.h"
#include <stdio.h>
#include <stdlib.h>

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

void troca(struct racional **v, int i, int j)
{
    struct racional *aux = (struct racional *) malloc(sizeof(struct racional *));
    aux = v[i];
    v[j] = v[i];
    v[i] = aux;
    free(aux);
}

/*identifica e elimina todos os números racionais inválidos dentro do vetor, esse algoritmo é quadrático, porém ele funciona para qualquer instância desse problema*/
void elimina_invalido(struct racional **v, int *n)
{
    int i = 0;
    while (i < *n) {
        if (!valido_r(v[i])) {
            destroi_r(v[i]);
            (*n)--;
            while ((*n) > i) {
                if (valido_r(v[*n])) {
                    v[i] = v[*n];
                    /* eu nao consegui tirar esse break daqui de maneira
                     * eficiente */
                    break;
                }
                destroi_r(v[*n]);
                (*n)--;
            }
        }

        i++;
    }
}

void libera_vetor(struct racional **vetor, int n)
{
    for (int i=0; i < n; i++)
    {
        destroi_r(vetor[i]);
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
    int n;

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

    libera_vetor(vetorPointers, n);
    free(vetorPointers);
    destroi_r(soma);


    return 0;
}
