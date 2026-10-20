#include <stdio.h>
#include "Fila_Chamados.h"

// Prepara a estrutura da fila zerando os contadores (como limpar uma aba no Excel)
void inicializar_fila(Fila_Chamados* f) {
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
}

// Adiciona um chamado na última linha disponível
int enfileirar_chamado(Fila_Chamados* f, Chamado c) {
    if (f->tamanho >= MAX_FILA) {
        printf("\n[ERRO] A fila de chamados esta cheia!\n");
        return 0; // Falha
    }
    f->capacidade[f->fim] = c;
    f->fim = (f->fim + 1) % MAX_FILA; // Lógica de fila circular
    f->tamanho++;
    return 1; // Sucesso
}

// Pega o primeiro chamado da fila para ser atendido (retira da espera)
Chamado desenfileirar_chamado(Fila_Chamados* f) {
    Chamado c_vazio;
    c_vazio.id_chamado = -1; // Retorna um chamado inválido caso a fila esteja vazia

    if (f->tamanho == 0) {
        printf("\n[AVISO] Nao ha chamados pendentes na fila.\n");
        return c_vazio;
    }

    Chamado c = f->capacidade[f->inicio];
    f->inicio = (f->inicio + 1) % MAX_FILA;
    f->tamanho--;
    return c;
}

// Mostra o relatório de todos os chamados na fila
void listar_chamados(Fila_Chamados f) {
    if (f.tamanho == 0) {
        printf("\nFila de chamados vazia.\n");
        return;
    }

    printf("\n--- LISTA DE CHAMADOS NA FILA (%d pendentes) ---\n", f.tamanho);
    int idx = f.inicio;
    for (int i = 0; i < f.tamanho; i++) {
        exibir_chamado(&f.capacidade[idx]);
        idx = (idx + 1) % MAX_FILA;
    }
}