#ifndef FILA_CHAMADOS_H
    #define FILA_CHAMADOS_H

    #include "Chamado.h"

    #define MAX_FILA 100

    typedef struct {
        Chamado* elementos;
        int capacidade;
        int inicio;
        int fim;
        int tamanho;
    } Fila_Chamados;

    Fila_Chamados criar_fila(int capacidade);
    void enfileirar_chamado(Fila_Chamados* f, Chamado c);
    Chamado desenfileirar_chamado(Fila_Chamados* f);
    int fila_vazia(Fila_Chamados* f);
    int fila_cheia(Fila_Chamados* f);
    void liberar_fila(Fila_Chamados* f);

#endif // FILA_CHAMADOS_H