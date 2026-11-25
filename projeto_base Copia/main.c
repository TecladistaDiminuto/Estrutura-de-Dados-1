/*
 * ATIVIDADE: BATATA QUENTE (LISTA CIRCULAR)
 *
 * N jogadores, numerados de 1 a N, estao sentados em roda.
 * A batata comeca com o jogador 1. A cada rodada, ela e passada K vezes
 * para o jogador seguinte, e quem estiver com ela ao final das K passagens
 * e eliminado. A rodada seguinte comeca com o jogador que vinha depois do
 * eliminado. O jogo termina quando sobra apenas um jogador.
 *
 * Exemplo: com N = 5 e K = 2, o jogador 1 passa para o 2, que passa para
 * o 3, e o 3 e eliminado. A proxima rodada comeca com o jogador 4.
 *
 * Transforme a lista deste projeto em uma lista circular e implemente o
 * jogo. O programa deve imprimir a ordem de eliminacao e o vencedor.
 */

#include <stdio.h>
#include "lista.h"

int main(void) {
    Lista *roda = lista_criar();
    int n, k, i;

    if (roda == NULL) {
        printf("Erro: nao foi possivel criar a lista.\n");
        return 1;
    }

    printf("Quantidade de jogadores (N): ");
    if (scanf("%d", &n) != 1) {
        printf("Erro: entrada invalida para N.\n");
        lista_destruir(roda);
        return 1;
    }
    printf("Quantidade de passagens (K): ");
    if (scanf("%d", &k) != 1) {
        printf("Erro: entrada invalida para K.\n");
        lista_destruir(roda);
        return 1;
    }

    if (n < 1 || k < 1) {
        printf("Erro: N e K devem ser maiores que zero.\n");
        lista_destruir(roda);
        return 1;
    }

    for (i = 1; i <= n; i++) {
        if (!lista_inserir_fim(roda, i)) {
            printf("Erro: nao foi possivel adicionar todos os jogadores.\n");
            lista_destruir(roda);
            return 1;
        }
    }

    printf("Roda: ");
    lista_imprimir(roda);

    printf("Ordem de eliminacao: ");
    while (lista_tamanho(roda) > 1) {
        int eliminado;
        lista_eliminar_contando(roda, k, &eliminado);
        printf("%d ", eliminado);
    }

    int vencedor;
    lista_obter_inicio(roda, &vencedor);
    printf("\nVencedor: %d\n", vencedor);

    lista_destruir(roda);
    return 0;
}
