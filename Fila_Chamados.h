#ifndef FILA_CHAMADOS_H
    
    #define FILA_CHAMADOS_H

    #include "Chamado.h" // inclui o cabeçalho Chamado.h para usar a estrutura Chamado

    //#define MAX_FILA 100 (removido por incoerência com a definição de capacidade dinâmica)

    typedef struct {
        Chamado* elementos;
        int capacidade;
        int inicio;
        int fim;
        int tamanho;
    } Fila_Chamados;

    Fila_Chamados criar_fila(int capacidade); // pede espaço na memória para guardar o número de chamados especificado e prepara os marcadores de início, fim e tamanho da fila.
    void enfileirar_chamado(Fila_Chamados* f, Chamado c); // adiciona um chamado na última linha disponível da fila, se houver espaço.
    Chamado desenfileirar_chamado(Fila_Chamados* f); // remove e retorna o primeiro chamado da fila.
    int fila_vazia(Fila_Chamados* f); // verifica se a fila está vazia.
    int fila_cheia(Fila_Chamados* f); // verifica se a fila está cheia.
    void liberar_fila(Fila_Chamados* f); // libera a memória alocada para a fila.

#endif // FILA_CHAMADOS_H

// O erro estava na definição de MAX_FILA, que estava como uma constante fixa. Agora, a fila é criada com capacidade dinâmica, permitindo que o tamanho seja definido no momento da criação da fila.