#ifndef ENTIDADES_H
   
    #define ENTIDADES_H

    typedef struct {
        int id;
        char nome[100];
        char departamento[100];
    } Usuario; // Caracracterísticas do Usuário

    Usuario criar_usuario (
        int id,
        const char* nome,
        const char* departamento
    ); //assinatura das funções (como cabeçalho das Subs/Functions no VBA)

    typedef struct {
        int id;
        char nome[100];
        char especialidade[255];
    } Tecnico; // Características do Técnico

    Tecnico criar_tecnico (
        int id,
        const char* nome,
        const char* especialidade
    ); //Assinatura das funções (como cabeçalho das Subs/Functions no VBA)

#endif // ENTIDADES_H
