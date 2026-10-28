#include <stdio.h>
#include <stdlib.h> // Necessário para usar malloc() e free()
#include "Fila_Chamados.h"

// Cria a fila alocando a memória dinamicamente com base na capacidade informada
Fila_Chamados criar_fila(int capacidade) {
    Fila_Chamados f;
    f.capacidade = capacidade;
    f.inicio = 0;
    f.fim = 0;
    f.tamanho = 0;
    
    // Aloca espaço no "armazém" de memória para a quantidade solicitada de chamados
    f.elementos = (Chamado*) malloc(capacidade * sizeof(Chamado));
    
    if (f.elementos == NULL) {
        printf("\n[ERRO] Falha ao alocar memoria para a fila!\n");
        f.capacidade = 0;
    }
    
    return f;
}

// Verifica se a fila está vazia (retorna 1 para sim, 0 para não)
int fila_vazia(Fila_Chamados* f) {
    return (f->tamanho == 0);
}

// Verifica se a fila atingiu o limite da sua capacidade (retorna 1 para sim, 0 para não)
int fila_cheia(Fila_Chamados* f) {
    return (f->tamanho >= f->capacidade);
}

// Adiciona um chamado no final da fila (se houver espaço)
void enfileirar_chamado(Fila_Chamados* f, Chamado c) {
    if (fila_cheia(f)) {
        printf("\n[ERRO] A fila de chamados esta cheia!\n");
        return;
    }
    
    // Insere o chamado na posição 'fim' do vetor 'elementos'
    f->elementos[f->fim] = c;
    
    // Lógica de fila circular utilizando a capacidade dinâmica
    f->fim = (f->fim + 1) % f->capacidade;
    f->tamanho++;
}

// Remove e retorna o primeiro chamado da fila
Chamado desenfileirar_chamado(Fila_Chamados* f) {
    Chamado c_vazio;
    c_vazio.id_chamado = -1; // Retorna um ID inválido para sinalizar erro/vazio

    if (fila_vazia(f)) {
        printf("\n[AVISO] Nao ha chamados pendentes na fila.\n");
        return c_vazio;
    }

    // Pega o chamado que está no início da fila
    Chamado c = f->elementos[f->inicio];
    
    // Avança o ponteiro do início de forma circular
    f->inicio = (f->inicio + 1) % f->capacidade;
    f->tamanho--;
    
    return c;
}

// Libera o bloco de memória que foi alocado para os elementos da fila
void liberar_fila(Fila_Chamados* f) {
    if (f->elementos != NULL) {
        free(f->elementos); // Devolve a memória para o sistema operacional
        f->elementos = NULL;
    }
    f->capacidade = 0;
    f->tamanho = 0;
    f->inicio = 0;
    f->fim = 0;
}