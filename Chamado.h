#ifndef CHAMADO_H

    #define CHAMADO_H

    #include "Entidades.h" // inclui o cabeçalho Entidades.h para usar as estruturas Usuario e Tecnico

    typedef struct {
        int id_chamado; 
        Usuario solicitante; 
        Tecnico tecnico_responsavel;
        char descricao[255];
        char resposta[255];
        int status; // 0 - Aberto, 1 - Em andamento, 2 - Concluído

    } Chamado; // Características do Chamado

    // Funções para criar e manipular chamados

    Chamado abrir_chamado(int id, Usuario u, const char* desc); //Cria e preenche um chamado do zero.
    void atender_chamado(Chamado* c, Tecnico t); // Atribui um técnico responsável ao chamado e muda o status para "Em andamento".
    void fechar_chamado(Chamado* c, const char* resposta); // Escreve a resposta do técnico e muda o status para "Concluído".
    void exibir_chamado(Chamado* c); // Exibe as informações do chamado, incluindo o status e a resposta, se houver.

#endif // CHAMADO_H