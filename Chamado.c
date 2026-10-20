#include <stdio.h>
#include <string.h>
#include "Chamado.h"

// Abre o chamado com status 0 (pendente)
Chamado abrir_chamado(int id, Usuario u, const char* descricao) {
    Chamado c;
    c.id_chamado = id;
    c.solicitante = u;
    c.tecnico_responsavel.id = 0; // Nenhum técnico atribuído ainda
    strncpy(c.descricao, descricao, sizeof(c.descricao) - 1);
    c.descricao[sizeof(c.descricao) - 1] = '\0'; // Garantir terminação nula
    c.resposta[0] = '\0'; // Nenhuma resposta ainda
    c.status = 0; // Chamado aberto
    return c;
}

// Atribui um técnico ao chamado e muda o status para em andamento (1)
void atender_chamado(Chamado* c, Tecnico t) {
    c->tecnico_responsavel = t;
    c->status = 1; // Em andamento
}

//Finaliza o chamado com a solução dada pelo técnico e status concluído (2)
void fechar_chamado(Chamado* c, const char* resposta) {
    strncpy (c->resposta, resposta, sizeof(c->resposta) - 1);
    c->resposta[sizeof(c->resposta) - 1] = '\0'; // Garantir terminação nula
    c->status = 2; // 2 = Concluído
}

// Imprime a "ficha" formatada na tela
void exibir_chamado(const Chamado* c) {
    printf("ID do Chamado: %d\n", c->id_chamado);
    printf("Solicitante: %s (Departamento: %s)\n", c->solicitante.nome, c->solicitante.departamento);
    if (c->tecnico_responsavel.id != 0) {
        printf("Técnico Responsável: %s (Especialidade: %s)\n", c->tecnico_responsavel.nome, c->tecnico_responsavel.especialidade);
    } else {
        printf("Técnico Responsável: Nenhum\n");
    }
    printf("Descrição: %s\n", c->descricao);
    printf("Resposta: %s\n", c->resposta);
    printf("Status: ");
    switch (c->status) {
        case 0:
            printf("Aberto\n");
            break;
        case 1:
            printf("Em andamento\n");
            break;
        case 2:
            printf("Concluído\n");
            break;
        default:
            printf("Desconhecido\n");
            break;
    }
}