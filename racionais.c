#include "racionais.h"
#include <stdlib.h>

/* Maximo Divisor Comum entre a e b      */
/* calcula o mdc pelo metodo de Euclides */
int mdc (int a, int b){
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

/* Minimo Multiplo Comum entre a e b */
/* mmc = (a * b) / mdc (a, b)        */
int mmc (int a, int b){
    return a * (b / mdc(a, b));
}

struct racional *cria_r (long int numerador, long int denominador)
{   
    struct racional *r = malloc(sizeof(struct racional));
    r->num = numerador;
    r->den = denominador;
    return &r;
}

/* Libera o espaco alocado para o racional */
void destroi_r (struct racional *r)
{   
    
}

/*acessa e retorna o númerador de um número racional*/
long int numerador_r (struct racional *r)
{
    return r->num;
}

/* acessa e retorna o denominador de um racional */
long int denominador_r (struct racional *r)
{
    return r->den;
}

/* Retorna 1 se o racional r eh valido ou 0 se for inválido
 * Um racional eh invalido se o denominador for zero ou
 * se ele não tiver sido alocado. */
int valido_r (struct racional *r)
{
    return (!(r->den == 0));
}

void imprime_r (struct racional *r)
{
    if (!valido_r(r))
    {
        printf("INVALIDO ");
        return;
    }
    else if ((r->num == 0) || (r->den == 1))
    {
        printf("%d ", r->num);
        return;
    }
    else if (((r->num < 0) && (r->num < 0)) || ((r->num > 0) && (r->den < 0)))
    {
        printf("%d/%d ", -r->num, -r->den);
        return;
    }
    printf("%d/%d ", r->num, r->den);
}

/* Compara dois números racionais r1 e r2.
 * Retorna -2 se r1 ou r2 for invalido ou se o respectivo ponteiro for nulo.
 * Retorna -1 se r1 < r2; 0 se r1 = r2; 1 se r1 > r2.
 * Atencao: faca a comparacao normalizando os denominadores pelo MMC.
 * Fazer a comparacao baseado na divisao de numerador pelo denominador
 * pode resultar em erro numerico e falsear o teste. */
int compara_r (struct racional *r1, struct racional *r2)
{
    int MMC = mmc(r1->den, r2->den);
    int num1 = MMC/r1->den*r1->num;
    int num2 = MMC/r2->den*r2->num;
    if (num1 == num2)
    {
        return 0;
    }
    if (num1 > num2)
    {
        return 1;
    }
    return -1;
}

/* Simplifica o número racional indicado no parâmetro.
 * Por exemplo, se o número for 10/8 devera mudar para 5/4.
 * Retorna 1 em sucesso e 0 se r for inválido ou o ponteiro for nulo.
 * Se ambos numerador e denominador forem negativos, o resultado é positivo.
 * Se o denominador for negativo, o sinal deve migrar para o numerador. */
int simplifica_r (struct racional *r)
{
    if (valido_r(r))
    {
        int maiorDivisor = mdc(r->num, r->den);
        r->num = r->num / maiorDivisor;
        r->den = r->den / maiorDivisor;
        return 1;
    }
    else{
        return 0;
    }
}

/* Coloca em *r3 a soma simplificada dos racionais *r1 e *r2.
 * Retorna 1 em sucesso e 0 se r1 ou r2 for nulo ou inválido. */
int soma_r (struct racional *r1, struct racional *r2, struct racional *r3)
{
    int minMC = mmc(r1->den, r2->den);
    r3->num = minMC/r1->den*r1->num + minMC/r2->den*r2->num;
    r3->den = minMC;
    simplifica_r(r3);
    return 1;
}

/* Coloca em *r3 a diferença simplificada dos racionais *r1 e *r2.
 * Retorna 1 em sucesso e 0 se r1 ou r2 for nulo ou inválido. */
int subtrai_r (struct racional *r1, struct racional *r2, struct racional *r3)
{
    int minMC = mmc(r1->den, r2->den);
    r3->num = minMC/r1->den*r1->num - minMC/r2->den*r2->num;
    r3->den = minMC;
    simplifica_r(r3);
    return 1;
}

/* Coloca em *r3 o produto simplificado dos racionais *r1 e *r2.
 * Retorna 1 em sucesso e 0 se r1 ou r2 for nulo ou inválido. */
int multiplica_r (struct racional *r1, struct racional *r, struct racional *r32)
{
    r32->num = r1->num * r->num;
    r32->den = r1->den * r->den;
    simplifica_r(r32);
    return 1;
}

/* Coloca em *r3 a divisão simplificada do racional *r1 por *r2.
 * Retorna 1 em sucesso e 0 se r1 ou r2 for nulo ou inválido. */
int divide_r (struct racional *r1, struct racional *r2, struct racional *r3)
{
    r3->num = r1->num * r2->den;
    r3->den = r1->den * r2->num;
    if (r3->den == 0)
    {
        return 0;
    }
    simplifica_r(r3);
    return 1;
}