#include <stdio.h>
#include <string.h>
#include "Entidades.h"

// Função para preencher os dados do usuário
Usuario criar_usuario(int id, const char* nome, const char* departamento) {
    Usuario u;
    u.id = id;
    strncpy(u.nome, nome, sizeof(u.nome) - 1);
    u.nome[sizeof(u.nome) - 1] = '\0'; // Garantir terminação nula
    strncpy(u.departamento, departamento, sizeof(u.departamento) - 1);
    u.departamento[sizeof(u.departamento) - 1] = '\0'; // Garantir terminação nula
    return u;
}

//Função para preencher os dados do técnico
Tecnico criar_tecnico(int id, const char* nome, const char* especialidade) {
    Tecnico t;
    t.id = id;
    strncpy(t.nome, nome, sizeof(t.nome) - 1);
    t.nome[sizeof(t.nome) - 1] = '\0'; // Garantir terminação nula
    strncpy(t.especialidade, especialidade, sizeof(t.especialidade) - 1);
    t.especialidade[sizeof(t.especialidade) - 1] = '\0'; // Garantir terminação nula
    return t;
}