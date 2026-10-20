#ifndef CHAMADO_H
    #define CHAMADO_H

    #include "Entidades.h"

    typedef struct {
        int id_chamado; 
        Usuario solicitante; 
        Tecnico tecnico_responsavel;
        char descricao[255];
        char resposta[255];
        int status; // 0 - Aberto, 1 - Em andamento, 2 - Concluído

    } Chamado; // Características do Chamado

    // Funções para criar e manipular chamados

    Chamado abrir_chamado(int id, Usuario u, const char* desc);
    void atender_chamado(Chamado* c, Tecnico t);
    void fechar_chamado(Chamado* c, const char* resposta);
    void exibir_chamado(Chamado* c);

#endif // CHAMADO_H